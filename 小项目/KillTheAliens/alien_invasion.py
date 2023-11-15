import sys

import pygame

from  settings import Settings
from ship import Ship
import game_fuctions as gf
from pygame.sprite import Group
from game_stats import GameStats
from scoreboard import Scoreboard
from button import Button
from background import  Background
from alien import Alien
def run_game():
    #初始化游戏并创建一个屏幕
    pygame.init()
    ai_settings = Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")

    #创建一个Play按钮
    play_button = Button(ai_settings,screen,"Play")
    #创建存储游戏统计信息的实例，并创建计分板
    stats = GameStats(ai_settings)
    sb = Scoreboard(ai_settings,screen,stats)
    # pygame.event.get()
    #创建一艘飞船,一个子弹编组和一个外星人编组
    ship = Ship(ai_settings,screen)
    #创建一个用于存储子弹的编组
    bullets = Group()
    #创建一个外星人
    # alien = Alien(ai_settings,screen)
    aliens = Group()
    # 创建外星人群
    gf.create_fleet(ai_settings, screen, ship, aliens)
    #设置背景色
    # bg_color = (ai_settings.bgg_color)
    pygame.mixer.init()
    pygame.mixer.music.load('music/bgm.mp3')
    pygame.mixer.music.play()
    '''分别用music和sound来播放背景音乐和音效'''
    #开始游戏的主循环
    while True:
        #监视键盘和鼠标事件
        gf.check_events(ai_settings,screen,stats,sb,play_button,ship,aliens,bullets)
        if stats.game_active:

            ship.update()
            gf.update_bullets(ai_settings,screen,stats,sb,ship,aliens,bullets)
            gf.update_aliens(ai_settings,stats,screen,sb,ship,aliens,bullets)
        gf.update_screen(ai_settings,screen,stats,sb,ship,aliens,bullets,play_button)

run_game()