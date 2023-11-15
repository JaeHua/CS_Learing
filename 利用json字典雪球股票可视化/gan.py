import requests
import csv
page = 1
headers = {
'Cookie':
'xq_a_token=715ae77c7b72c67549b80e153e894ef2e19f0446; xqat=715ae77c7b72c67549b80e153e894ef2e19f0446; xq_r_token=a1c71f74d5f0fd50f87640a0682c837e5a07f706; xq_id_token=eyJ0eXAiOiJKV1QiLCJhbGciOiJSUzI1NiJ9.eyJ1aWQiOi0xLCJpc3MiOiJ1YyIsImV4cCI6MTY5MjkyMzcyMSwiY3RtIjoxNjkwOTgzODI0NjgzLCJjaWQiOiJkOWQwbjRBWnVwIn0.V1uEN7eES3_szoroL-i9ekOdZkF0LqxyckCUOrHeYTWAmriTJ2JGQYeDgZvpFsxf6RW7_gE1Zu7dZkYDVY9NzLc6VvTkg9fF94gykraUw-NQX-0L3F_IHSH-tH-ZOo2toDc6fb3siLwgFrExaKjRqh6m60y1Sd-EFINfBdcWCu10irf7-UJ54Q0pNWZqp6YQ2pP7H_c_CkgcFmPg3AFfjCryHi1coLHLm3i9fWld4f0xxGFtHnIJfNMF64lQZ9jq870UaBcmG2WskaJ6YPLwiJaO9RLK95PGUR0Qe6ZhH_NpzAxrqCA5XVKjr9CwCs6fIDLlBRPtTlVLCGJs_qHf-g; u=331690983847015; device_id=e40f9e10e75cea02ba56c6fe11f7b24d; Hm_lvt_1db88642e346389874251b5a1eded6e3=1690983847; s=c411o3x2dj; Hm_lpvt_1db88642e346389874251b5a1eded6e3=1690984638',
'User-Agent':
'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.188'
}
with open('雪球股票.csv', mode='a',encoding="ANSI", newline='') as f:
    writer = csv.writer(f)
    writer.writerow(
        ['股票代码', '股票名称', '当前价', '涨跌额', '涨跌幅', '年初至今', '成交量', '成交额', 	'换手率', '市盈率(TTM)','股息率', '市值'])

for page_hum in range(1,168):
    print("------------正在爬取第" + str(page_hum) +"页------------")
    url = f"https://stock.xueqiu.com/v5/stock/screener/quote/list.json?page={page_hum}&size=30&order=desc&orderby=percent&order_by=percent&market=CN&type=sh_sz"

    resp = requests.get(url,headers=headers)
    #.json返回的是字典
    json_data = resp.json()

    data_list = json_data['data']['list']
    #循环遍历
    for data in data_list:
        symbol = data['symbol']
        name = data['name']
        current = data['current']
        chg = data['chg']
        first_percent = data['first_percent']
        current_year_percent = data['current_year_percent']
        volume = data['volume']
        amount = data['amount']
        pe_ttm= data['pe_ttm']
        market_capital= data['market_capital']
        turnover_rate = data['turnover_rate']
        dividend_yield = data['dividend_yield']
        print(symbol,name,current,chg,first_percent,current_year_percent,volume,amount,pe_ttm,market_capital,turnover_rate,dividend_yield)
        #保存数据
        with open ('雪球股票.csv',mode='a',encoding= "ANSI",newline='') as f:
            writer = csv.writer(f)
            writer.writerow([symbol,name,current,chg,first_percent,current_year_percent,volume,amount,pe_ttm,market_capital,turnover_rate,dividend_yield])
resp.close()