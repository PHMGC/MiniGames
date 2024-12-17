import os
import requests
from PIL import Image
from io import BytesIO

# https://www.chess.com/chess-themes/pieces/neo/300/{w,b}{k,q,p,n,b,r}.png
url = "https://www.chess.com/chess-themes/pieces/neo/300/"

for team in ["w", "b"]:
    if not os.path.exists(team):
        os.mkdir(team)
    for piece in ["k", "q", "p", "n", "b", "r"]:
        response = requests.get(url + team + piece + ".png")
        if response.status_code == 200:
            image = Image.open(BytesIO(response.content))
            image.save(f"{team}/{piece}.png")
        else:
            print("Error downloading", team, piece)
