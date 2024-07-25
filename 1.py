import math

BANANA = {"carbohidratos": 27, "calorias": 105}
ATUN = {"proteinas": 30, "calorias": 120}
ACEITE_DE_OLIVA = {"grasas": 1, "calorias": 9}


def zetadieta(C: int, P: int, G: int) -> int:
    calorias = 0
    calorias += math.ceil(C / BANANA["carbohidratos"]) * BANANA["calorias"]
    calorias += math.ceil(P / ATUN["proteinas"]) * ATUN["calorias"]
    calorias += math.ceil(G / ACEITE_DE_OLIVA["grasas"]) * ACEITE_DE_OLIVA["calorias"]

    return calorias


print(zetadieta(0, 0, 999))
print(zetadieta(1, 0, 0))
