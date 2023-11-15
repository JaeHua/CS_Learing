import pygame
from pygame.sprite import Sprite

class Ship(Sprite):
    '''初始化飞船并设置其初始位置'''
    def __init__(self,ai_settings,screen):
        super(Ship,self).__init__()
        self.screen = screen
        self.ai_settings = ai_settings
        '''加载飞船图形并且获取其外接图形'''
        self.image = pygame.image.load('images/alienship1.bmp')
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        '''将每艘飞船放到屏幕底部中央'''
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom -170

        #在飞船的属性center中存储小数值
        self.center = float(self.rect.centerx)
        #移动标志
        self.moving_right = False
        self.moving_left = False

    def update(self):
        '''根据移动标志调整飞船的位置'''
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.rect.centerx += self.ai_settings.ship_speed_factor
        if self.moving_left and self.rect.left > 0:
            self.rect.centerx -= self.ai_settings.ship_speed_factor

    def blitme(self):
        '''在指定位置绘制飞船'''
        self.screen.blit(self.image,self.rect)
    def center_ship(self):
        '''飞船居中'''
        self.center = self.screen_rect.centerx