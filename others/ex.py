import json

itemJson = '{"pr11": [1, "http://127.0.0.1:8000/media/home/images/newAvatar.jpg", "Thanda", "200", "nice"]}'

data = json.loads(itemJson)

for key in data:
    prodId = key

print(prodId)

