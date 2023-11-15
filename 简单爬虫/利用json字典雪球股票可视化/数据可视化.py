#导入模块
import pandas as pd
from pyecharts.globals import ThemeType
from pyecharts import options as opts
from pyecharts.charts import Bar
#准备数据
df = pd.read_csv('雪球股票.csv',encoding="ANSI")
l1=list(df['股票名称'].values)
l2=list(df['成交量'])
bar = (
    Bar(init_opts=opts.InitOpts(theme=ThemeType.LIGHT))
    .add_xaxis(l1[:10])
    .add_yaxis("成交量情况", l2[:10])
    .set_global_opts(title_opts=opts.TitleOpts(title="成交量"),
datazoom_opts=opts.DataZoomOpts())
)
# 生成render.html
bar.render()

