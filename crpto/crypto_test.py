from requests import Request, Session
from requests.exceptions import ConnectionError, Timeout, TooManyRedirects
import json

url = 'https://pro-api.coinmarketcap.com/v1/cryptocurrency/map'
parameters = {
  'start':'100',
  'limit':'2',
  'symbol' : "BTC"
}
headers = {
  'Accepts': 'application/json',
  'X-CMC_PRO_API_KEY': '0dcd91bf-8f37-473b-888a-f11b8b03c494',
}

session = Session()
session.headers.update(headers)

try:
  response = session.get(url, params=parameters)
  data = json.loads(response.text)
  """json_object = json.loads(data)"""
  """json_formatted_str = json.dumps(json_object, indent=2)"""

  print(data)
  
except (ConnectionError, Timeout, TooManyRedirects) as e:
  print(e)