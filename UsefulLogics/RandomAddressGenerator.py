# Public-share
import random

country=["India","USA"] #only India and USA - add country names as you wish

India=["Tamil Nadu/Chennai,600001?Coimbatore,641001?Tirupur,641601?Erode,638001?Vellore,635852",
      "Karnataka/Banglore,560001?Belgaum,560731?Mysuru,570027?Kolar,560321?Udupi,570335",
      "Kerala/Wayand,670163?Alappuzha,670300?Ernakulam,670394?Idukki,670298?Kannur,670383",
      "Madhya Pradesh/Gwalior,450163?Guna,450108?Jabalpur,450192?Katni,450216?Morena,450203",
      "Maharashtra/Hingoli,400118?Beed,400330?Amravati,400455?Pune,400792?Nashik,400671",
      "Andhra Pradesh/Chitoor,515894?Kadapa,515831?Nellore,515777?Vizag,515689?Kurnool,515766",
      "Punjab/Amritsar,140377?Fazilka,140001?Firozpur,140266?Mansa,14093?Mohali,140053"]

USA=["Alaska/Akiak,99552?Big Lake,99652?Chicken,99732?Circle,99733?Clear,99704",
      "Arizona/Pheonix,85098?Scottsdale,85254?Gilbert,85233?Chandler,85225?Mesa,85201",
      "Arkansas/Adona,72001?Gateway,72733?Garfield,72732?Friendship,71942?Guy,72061",
      "California/Dalycity,94014?Palo Alto,94301?Brooks,95606?Camino,95709?Cool,95614",
      "Colorado/Carr,80612?Fleming,80728?Idalia,80735?Parachute,81635?Paradox,81429",
      "Connecticut/Brookfield,6804?Derby,6418?Greenwich,6836?Madison,6443?Oxford,6478",
      "Hawaii/Aiea,96701?Hilo,96720?Honolulu,96801?Koloa,96756?Pearl Harbor,96860"]


i = 0 

print("State,City,Pincode,Country") #headers for output

n = 500 #controls count of rows being generated

while i<n :
    r=random.randrange(0,2)
    r1=random.randrange(0,7)
    if r==0:
        state = India[r1].split('/')[0]
        city_list = India[r1].split('/')[1]
        city = city_list.split('?')
        r2=random.randrange(0,5)
        print(state+","+city[r2]+",India")
    """
    else:
        state = USA[r1].split('/')[0]
        city_list = USA[r1].split('/')[1]
        city = city_list.split('?')
        r2=random.randrange(0,5)
        print(state+","+city[r2]+",India") 
    """
    i+=1
      

