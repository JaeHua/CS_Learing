import sys
import datetime
import pygame
from bullet import Bullet
from alien import Alien
from time import sleep
from  background import Background
#按下去
def check_keydown_events(event,ai_settings,screen,ship,bullets):
    '''响应按键'''
    if event.key == pygame.K_RIGHT:
       #向右移动飞船
         ship.moving_right = True
    elif event.key == pygame.K_LEFT:
           ship.moving_left = True
    elif event.key == pygame.K_SPACE:
        fire_bullet(ai_settings,screen,ship,bullets)
    elif event.key ==pygame.K_q:
        sys.exit()

#松开键
def check_up_events(event,ship):
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False
def check_events(ai_settings,screen,stats,sb,play_button,ship,aliens,bullets):
    '''响应按键和鼠标'''
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            write_high_score(stats)
            sys.exit()
        elif event.type == pygame.KEYDOWN:
            check_keydown_events(event,ai_settings,screen,ship,bullets)
        elif event.type == pygame.KEYUP:
            #右是优先的
            check_up_events(event,ship)
        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x,mouse_y = pygame.mouse.get_pos()
            check_play_button(ai_settings,screen,stats,sb,play_button,ship,aliens,bullets,mouse_x,mouse_y)

def write_high_score(stats):
    Note = open('datas.txt',mode = 'w')
    Note.write(str(stats.high_score) + '\n')
    Note.close()
def  check_play_button(ai_settings,screen,stats,sb,play_button,ship,aliens,bullets,mouse_x,mouse_y):
        '''在玩家单击play时候开始游戏'''
        button_clicked  = play_button.rect.collidepoint(mouse_x,mouse_y)
        if button_clicked and not stats.game_active:
            #重置游戏设置
            ai_settings.initialize_dynamic_settings()
            #隐藏光标
            pygame.mouse.set_visible(False)
            #重置游戏信息
            stats.reset_stats()
            stats.game_active = True
            #重置计分牌
            sb.prep_score()
            sb.prep_high_score()
            sb.prep_level()
            sb.prep_ships()
            #清空外星人和列表
            aliens.empty()
            bullets.empty()
            #创建一群新的外星人，并让飞船居中
            create_fleet(ai_settings,screen,ship,aliens)
            ship.center_ship()
def update_screen(ai_settings,screen,stats,sb,ship,aliens,bullets,play_button):
    '''更新屏幕的图像，并切换到新屏幕'''
    # 添加背景图就会很慢
    # bg_image = Background('images/bg.bmp', [0, 0])
    # screen.blit(bg_image.image, bg_image.rect)
    #每次循环都重绘屏幕
    screen.fill(ai_settings.bgg_color)
    ship.blitme()
    aliens.draw(screen)
    #在飞船和外星人后面重绘所有子弹
    for bullet in bullets.sprites():
        bullet.draw_bullet()
    #显示得分
    sb.show_score()
    if not stats.game_active:
        play_button.draw_button()
    #让最近的绘制可见
    pygame.display.flip()
def update_bullets(ai_settings,screen,stats,sb,ship,aliens,bullets):
    #更新子弹位置
    bullets.update()
    # 删除已经消失的子弹
    for bullet in bullets.copy():
        if bullet.rect.bottom < 0:
            bullets.remove(bullet)
    check_bullet_alien_collisions(ai_settings,screen,stats,sb,ship,aliens,bullets)

def check_bullet_alien_collisions(ai_settings,screen,stats,sb,ship,aliens,bullets):
    #检查是否有子弹击中了敌人
    #如果击中，删除相应的子弹和外星人
    collisions = pygame.sprite.groupcollide(bullets,aliens,True,True)

    if collisions:
        #如果外星人群被消灭，提高一个等级
        for aliens in collisions.values():
            play_sound()
            stats.score += ai_settings.alien_points*len(aliens)
            sb.prep_score()
        check_high_score(stats,sb)
    if len(aliens) == 0:
        #删除现有的子弹,加快游戏节奏，并新建一群外星人
        bullets.empty()
        ai_settings.increase_speed()
        #提高等级
        stats.level += 1
        sb.prep_level()

        create_fleet(ai_settings,screen,ship,aliens)
    #打印子弹数目
    print(len(bullets))

#发射子弹
def fire_bullet(ai_settings,screen,ship,bullets):
    # 创建一颗子弹，并加到编组bullets编组中
    if len(bullets) < ai_settings.bullet_allowed:
        new_bullet = Bullet(ai_settings, screen, ship)
        bullets.add(new_bullet)
def create_fleet(ai_settings,screen,ship,aliens):
    '''创建外星人群'''
    #创建一个外星人，并计算一行最大考验容纳多少外星人
    alien = Alien(ai_settings,screen)
    alien_width = alien.rect.width
    number_aliens_x = get_number_aliens_x(ai_settings,alien.rect.width)
    number_rows = get_number_rows(ai_settings,ship.rect.height,alien.rect.height)
    #创建第一行外星人
    for row_number in range(number_rows):
        for alien_number in range(number_aliens_x):
            creat_alien(ai_settings, screen, aliens, alien_number,row_number)
def get_number_aliens_x(ai_settings,alien_width):
    #计算每行容纳多少外星人
    available_space_x = ai_settings.screen_width - 2 * alien_width
    number_aliens_x = int(available_space_x / (2.5* alien_width))
    return number_aliens_x

def creat_alien(ai_settings,screen,aliens,alien_number,row_number):
    # 创建一个外星人并加入当前行
    alien = Alien(ai_settings, screen)
    alien_width = alien.rect.width
    alien.x = alien_width + 2 * alien_width * alien_number
    alien.rect.x = alien.x
    alien.rect.y = alien.rect.height + 2*alien.rect.height*row_number -20
    aliens.add(alien)

def get_number_rows(ai_settings,ship_height,alien_height):
    '''计算屏幕可以容纳多少外星人'''
    available_space_y =(ai_settings.screen_height - (3*alien_height) -ship_height)
    number_rows = int(available_space_y / (3*alien_height))
    return number_rows

def check_fleet_edges(ai_settings,aliens):
    '''有外星人到达边缘时采取相应的措施'''
    for alien in aliens.sprites():
        if alien.check_edges():
            change_fleet_directipn(ai_settings,aliens)
            break

def change_fleet_directipn(ai_settings,aliens):
    '''将整群外星人下移，并改变他们的方向'''
    for alien in aliens.sprites():
        alien.rect.y += ai_settings.fleet_drop_speed
    ai_settings.fleet_direction *= -1

def ship_hit(ai_settings,stats,screen,sb,ship,aliens,bullets):
    '''响应被外星人撞到的飞船'''
    if stats.ships_left > 1:
        stats.ships_left -= 1;

        #更新计分板

        sb.prep_ships()
        #清空外星人列表和子弹列表
        aliens.empty()
        bullets.empty()
        #debug

        #创建一群新外星人，将飞船放到屏幕底部中央
        create_fleet(ai_settings,screen,ship,aliens)
        '''  self.rect.centerx = self.screen_rect.centerx
            self.rect.bottom = self.screen_rect.bottom -170'''
        ship.center_ship()
        #暂停
        sleep(0.9)
    else:
        stats.game_active = False
        now = datetime.datetime.now()
        write_high_score(stats)
        # sb.prep_high_score()
        with open('log.txt', mode='a') as file:
            file.write('Time: ' + str(now) + '\tScore: ' + str(stats.score) + '\tHigh Score: ' + str(
                stats.high_score) + '\tLevel: ' + str(stats.level) + '\n')
            file.close()
        #非活动状态，光标可见
        pygame.mouse.set_visible(True)

def check_aliens_bottom(ai_settings,stats,screen,sb,ship,aliens,bullets):
    '''检查是否有外星人到达了屏幕底端'''
    screen_rect = screen.get_rect()
    for alien in aliens.sprites():
        if alien.rect.bottom >= screen_rect.bottom - 170:
            #像飞船被撞到一样处理
            ship_hit(ai_settings,stats,screen,sb,ship,aliens,bullets)
            break
def update_aliens(ai_settings,stats,screen,sb,ship,aliens,bullets):
    '''检查是否有外星人位于屏幕边缘，并更新整群外星人的位置'''
    check_fleet_edges(ai_settings,aliens)
    '''更新外星人群中所有外星人位置'''
    aliens.update()

    #检测外星人和飞船之间的碰撞
    if pygame.sprite.spritecollideany(ship,aliens):
        ship_hit(ai_settings,stats,screen,sb,ship,aliens,bullets)
    #检查是否有外星人到达屏幕底端
    check_aliens_bottom(ai_settings,stats,screen,sb,ship,aliens,bullets)
def play_sound():
    # pygame.mixer.init()
    # pygame.mixer.music.load('music/biubiu.mp3')
    # pygame.mixer.music.play
    sound_effect = pygame.mixer.Sound('music/biubiu.mp3')
    pygame.mixer.Sound.play(sound_effect)
def check_high_score(stats,sb):
        '''检测是否产生了最高分'''
        if stats.score > stats.high_score:
            stats.high_score = stats.score
            sb.prep_high_score()

