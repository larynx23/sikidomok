---
header-includes:
  - \usepackage{enumitem}
  - \setlist[itemize,2]{label=$\circ$}
---

# Specifikáció — Síkidomok
### Vadoba Hunor


## Rövid áttekintés
A program feladata: síkidomok (kör, háromszög, négyzet) definiálása. Ezentúl feladata még a pont-tartalmazás vizsgálata, terület/kerület kiszámítása.


## Típusok és adatformátumok
- Típusok: `triangle`, `square`, `circle`, `point`
- A program képes fájlból és parancssorból beolvasni adatokat.
- Fájlformátum: minden alakzat egy sorban, mezők szóközzel elválasztva. Példa:
  - `triangle name 2.0 -1.0 3.0 -1.0`
    (azaz: `<type> <name> <cx> <cy> <vx> <vy>`)
  - Kör esetén `vx vy` egy pontot jelöl a kör kerületén; háromszög és négyzet esetén `vx vy` egy csúcs koordinátája.


## Pontok, tulajdonságok
- `C (cx,cy)`: az alakzat középpontja.
- `V (vx,vy)`: referenciapont, alakzattól függő jelentéssel:
  - `circle`: `V` a kör kerületén lévő pont — a sugár R = dist(C,V).
  - `triangle` és `square`: `V` egy csúcs koordinátája.
- `R`: az alakzat sugara (`C` és `V` távolsága)


## Parancsok — pontos szintaxis és példák
Minden parancs egy sorban, mezők szóközzel elválasztva. A parancsok pontos szintaxisa:

- `add <type> <name> <cx> <cy> <vx> <vy>`
  - Felvesz egy adott alakzatot.
  - Példa: `add triangle t1 2.0 -1.0 3.0 -1.0`
- `list`
  - Kiírja az összes definiált alakzatot egy sor/egy alakzat formátumban: `<name>: <type> <cx> <cy> <vx> <vy>`
- `delete <name>`
  - Kitörli az adott alakzatot.
  - Példa: `delete t1`
- `contains <name> <x> <y>`
  - Megvizsgálja, hogy a `<x> <y>` pont rajta van-e a `<name>` alakzaton.
  - Példa: `contains t1 1.0 0.0`
- `perimeter <name>` vagy `p <name>`
  - Megadja a megadott alakzat kerületét.
  - Példa: `p t1`
- `area <name>` vagy `a <name>`
  - Megadja a megadott alakzat területét.
  - Példa: `a t1`
- Fájl beolvasása parancssorból:
  - `load <filename>` — a fájl sorait ugyanazzal a mezőfelépítéssel várja, mint az `add` parancs paraméterei.

Minden parancs pontosan a fenti token-szintaxist várja; további szóközök megengedettek, de mezők sorrendét és számát be kell tartani.


## Kimeneti formátum — pontos formátum és példák
- `add`: siker esetén `OK: added <name>`; hiba esetén `ERROR: <message>`.
- `list`: minden sor: `<name>: <type> <cx> <cy> <vx> <vy>` (szóközökkel elválasztva).
- `delete`: siker: `OK: deleted <name>`; ha nincs ilyen: `ERROR: unknown shape '<name>'`.
- `contains`: siker: `YES <name>` ha a pont rajta van, különben `NO <name>`; ha ismeretlen név: `ERROR: unknown shape '<name>'`.
- `perimeter` / `area`: siker: `<name> <metric> <value>` ahol `<metric>`: `perimeter` vagy `area`, `<value>` lebegőpontos szám (pl. `t1 perimeter 12.5664`);
  - hiba: `ERROR: unknown shape '<name>'`.
- `load`: siker: `OK: loaded <n> shapes from <filename>`; hiba példák: `ERROR: file not found '<filename>'`, `ERROR: parse error on line <k>: <reason>`.


## Hibakezelés — pontos hibaüzenetek
- Duplikált név: `ERROR: duplicate shape '<name>'`.
- Hibás számformátum: `ERROR: invalid number or not a number`.
- Ismeretlen parancs: `ERROR: unknown command '<cmd>'`.
