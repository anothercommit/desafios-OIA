import math

BANANA = {"carbs": 27, "calorias": 105}
ATUN = {"proteinas": 30, "calorias": 120}
ACEITE = {"grasas": 1, "calorias": 9}


def zetadietaLegible(C: int, P: int, G: int) -> int:
    # VERSION LEGIBLE
    calorias = 0

    if C > 0:
        calorias += math.ceil(C / BANANA["carbs"]) * BANANA["calorias"]
    if P > 0:
        calorias += math.ceil(P / ATUN["proteinas"]) * ATUN["calorias"]
    if G > 0:
        calorias += math.ceil(G / ACEITE["grasas"]) * ACEITE["calorias"]

    return calorias


print(zetadietaLegible(88, 90, 50))


def zetadietaConciso(C: int, P: int, G: int) -> int:
    # VERSION CONCISA
    return (
        (math.ceil(C / BANANA["carbs"]) * BANANA["calorias"] if C > 0 else 0)
        + (math.ceil(P / ATUN["proteinas"]) * ATUN["calorias"] if P > 0 else 0)
        + (math.ceil(G / ACEITE["grasas"]) * ACEITE["calorias"] if G > 0 else 0)
    )


print(zetadietaConciso(88, 90, 50))
