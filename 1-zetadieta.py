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
        (math.ceil(C / 27) * 105 if C > 0 else 0)  # bananas
        + (math.ceil(P / 30) * 120 if P > 0 else 0)  # atun
        + (math.ceil(G / 1) * 9 if G > 0 else 0)  # aceite de oliva
    )


print(zetadietaConciso(88, 90, 50))
