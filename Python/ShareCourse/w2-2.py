import pandas as pd
import requests
import bs4

""" Practice Excel """
df2 = pd.read_excel("DropAP_Phase_II_SIT_Full_test_0921.xlsx", sheetname="Test Result")
#print(df2)


""" Practice Web Crawler(Web Scapying) """
res = requests.get("https://www.jkforum.net/forum.php?mod=viewthread&tid=8310117&extra=page%3D1&ordertype=1&threads=thread")
#print(res.text)

soup = bs4.BeautifulSoup(res.text, "html.parser")
#print(soup.title.string)

payload = {
    "FromCity":"0",
    "FromStation":"",
    "FromStationName":"",
    "ToCity":"",
    "ToStation":"",
    "ToStationName":"",
    "TrainClass":"",
    "searchdate":"",
    "FromTimeSelect":"",
    "ToTimeSelect":"",
    "Timetype":""
}

res_post = requests.post("http://twtraffic.tra.gov.tw/twrail/TW_SearchResult.aspx", data= payload)
#print(res_post.text)




res_eyny = requests.get("http://www.eyny.com/search.php?mod=forum&searchid=114903&orderby=lastpost&ascdesc=desc&searchsubmit=yes&srchfrom=0&kw=%E7%BF%94%E5%A4%AA")
#print(res_eyny.text)
soup_eyny = bs4.BeautifulSoup(res_eyny.text, "html.parser")
print(soup_eyny.select("img"))
"""
film_name = pd.Series()
for film in soup_eyny.select("alt")
    film_name = film_name.append(pd.Series([file.string])).reset_index(drop=True)

print(film_name)
"""