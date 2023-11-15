import pygame.sprite
from pygame.sprite import Sprite

class Background(Sprite):
    def __init__(self, image_file, location):
        super().__init__()
        self.image = pygame.image.load(image_file).convert()
        self.image = pygame.transform.scale(self.image, (1200, 1200))
        self.rect = self.image.get_rect()
        self.rect.left, self.rect.top = location
        # 将自己添加到所有分组中
        # self.add(all_sprites, bg_group)