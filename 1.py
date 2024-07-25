import math

BANANA = {"carbohidratos": 27, "calorias": 105}
ATUN = {"proteinas": 30, "calorias": 120}
ACEITE = {"grasas": 1, "calorias": 9}


def zetadieta(C: int, P: int, G: int) -> int:
    return (
        math.ceil(C / BANANA["carbohidratos"]) * BANANA["calorias"]
        + math.ceil(P / ATUN["proteinas"]) * ATUN["calorias"]
        + math.ceil(G / ACEITE["grasas"]) * ACEITE["calorias"]
    )


print(zetadieta(88, 90, 50))
