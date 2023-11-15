class GameStats():
    '''跟踪游戏消息'''
    def __init__(self,ai_settings):
        '''初始化统计信息'''
        self.ai_settings =  ai_settings
        self.reset_stats()
        #游戏刚启动的时候处于活动状态
        self.game_active = False
        self.score = 0
        # 任何情况下都不会重置最高分
        self.high_score = 0
    def read_high_score(self):
        with open('datas.txt', mode='r') as file:
            content = file.read()
            if content == '':
                content = '0'
        return content
        print(content)

    def reset_stats(self):
        '''初始化在游戏运行期间可能变化的统计信息'''
        self.ships_left = self.ai_settings.ship_limit
        self.score = 0
        self.level = 1
        self.high_score = 0
        #比较文件中的最高分和现在的最高分
        save_high_score = self.read_high_score()
        if int(save_high_score) > self.high_score:
            self.high_score = int(save_high_score)

