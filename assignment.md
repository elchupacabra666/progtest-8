# Řazení spojového seznamu

Úkolem je realizovat sadu funkcí (ne celý program, jen funkce) pro práci se spojovými seznamy. Funkce umožní seznam snadno vytvářet, mazat a řadit.

Při řešení problému se setkáte s následujícími deklaracemi:

## `TITEM`

Tato struktura reprezentuje prvek jednosměrně zřetězeného spojového seznamu. Deklarace struktury je pevně daná v testovacím prostředí, vaše implementace bude tuto nezměněnou deklaraci používat (nemůže/nesmí ji měnit). Ve struktuře jsou následující složky:

- **`m_Next`** - ukazatel na další prvek ve spojovém seznamu, hodnota `NULL` pro poslední prvek.
- **`m_Name`** - řetězec s názvem prvku seznamu.
- **`m_Secret`** - tajná data přičleněná k této položce seznamu. Vaše implementace s touto složkou nepotřebuje pracovat a nesmí ji měnit (výjimkou je inicializace ve funkci `newItem`).

## Funkce k implementaci

### `TITEM * newItem ( const char * name, TITEM * next )`

Tato funkce vytvoří nový záznam `TITEM`. Paměť pro strukturu budete alokovat dynamicky. Funkce navíc zkopíruje jméno a odkaz na další prvek z parametrů do složek `m_Next` a `m_Name`. Složku `m_Secret` funkce vyplní nulovými bajty (`'\0'`). Návratovou hodnotou funkce je ukazatel na takto vytvořenou a inicializovanou strukturu `TITEM`. Implementace funkce je vaším úkolem.

### `void freeList ( TITEM * l )`

Funkce slouží k pohodlnému výmazu spojového seznamu. Parametrem je počátek mazaného spojového seznamu `l`. Funkce zajistí uvolnění všech prostředků, které seznam zabíral. Implementace funkce je vaším úkolem.

### `TITEM * sortList ( TITEM * l, int ascending )`

Funkce slouží k seřazení prvků ve spojovém seznamu. Parametrem je počátek řazeného spojového seznamu `l` a požadované seřazení `ascending`. Funkce zajistí přeskupení prvků v zadaném seznamu tak, aby pořadí vyhovovalo požadovanému uspořádání. Funkce nesmí prvky původního seznamu uvolňovat (např. vrátit jejich nově vytvořenou kopii). Naopak, musí přepojit odkazy existujících prvků a vrátit ukazatel na první prvek takto vzniklého seznamu.

- **Kritériem pro řazení** je název v prvku seznamu (`m_Name`). Řetězce se budou porovnávat s rozlišením malých a velkých písmen (case-sensitive).
- **Požadované uspořádání** je vzestupné (parametr `ascending` není nula) nebo sestupné (parametr `ascending` je roven nule).
- Funkce musí zajistit, že **řazení je stabilní**.

## Odevzdání

Odevzdávejte zdrojový soubor, který obsahuje implementaci požadovaných funkcí. Do zdrojového souboru přidejte i další vaše podpůrné funkce, které jsou z implementovaných funkcí volané. Funkce budou volané z testovacího prostředí, je proto důležité přesně dodržet zadané rozhraní funkce.

Za základ pro implementaci použijte kód z přiloženého archivu. Ukázka obsahuje testovací funkci `main`, uvedené hodnoty jsou použité při základním testu. Všimněte si, že vkládání hlavičkových souborů a funkce `main` jsou zabalené v bloku podmíněného překladu (`#ifdef/#endif`). Prosím, ponechte bloky podmíněného překladu i v odevzdávaném zdrojovém souboru. Podmíněný překlad vám zjednoduší práci.

Při kompilaci na vašem počítači můžete program normálně spouštět a testovat. Při kompilaci na Progtestu funkce `main` a vkládání hlavičkových souborů „zmizí“, tedy nebude kolidovat s hlavičkovými soubory a funkcí `main` testovacího prostředí.

## Poznámky

- Zkopírujte si ukázku z přiloženého archivu a použijte ji jako základ vašeho řešení.
- Do funkce `main` si můžete doplnit i další vaše testy, případně ji můžete libovolně změnit. Důležité je zachovat podmíněný překlad.
- Testovací prostředí omezuje použití některých funkcí, konkrétně neprojde volání knihovních funkcí `qsort` a `qsort_r` (ty stejně nejsou určené pro spojové seznamy).
- V povinných testech jsou zadávané relativně krátké spojové seznamy, efektivita použitého řadicího algoritmu není kritická.
- **První bonus** kontroluje rychlost implementovaného řadicího algoritmu. Vstupem je dlouhý seznam, kvadratické algoritmy řazení nemají šanci seznam seřadit ve vymezeném časovém limitu.
- **Druhý bonus** kontroluje rychlost a paměťové nároky implementovaného řadicího algoritmu. Vstupem je dlouhý seznam, kvadratické algoritmy řazení nemají šanci seznam seřadit ve vymezeném časovém limitu. Paměťový limit navíc nedává šanci na větší alokace - k dispozici je jen několik málo stovek KiB.
- V přiloženém ukázkovém zdrojovém souboru je vidět seznam dostupných hlavičkových souborů. Jiné hlavičkové soubory nejsou k dispozici a ani je nejde pomocí `#include` dodatečně vložit.
```
