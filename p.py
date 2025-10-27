class BitString:
    def __init__(a):
        a.str1 = []
        a.str2 = []
        a.temp1 = []
        a.temp2 = []
        a.resultat = []
        a.resultat_strok = ""
        a.addzero1 = 0
        a.addzero2 = 0

def vvodBitStroki(a, b):
    return list(input(b))

def vivodBitStroki(a, stroka):
    return ''.join(stroka)

def proverka_pravilnosti(a, stroka):
    for char in stroka:
        if char not in ['0', '1']:
            return False
    return True

def buildup0(a, stroka):
    addzero = 8 - len(stroka)
    temp = []
    for i in range(addzero):
        temp.append('0')
    for char in stroka:
        temp.append(char)
    return temp

def vych_conjunction(a, temp1, temp2):
    resultat = []
    for i in range(8):
        if temp1[i] == '1' and temp2[i] == '1': 
            resultat.append('1')
        else: 
            resultat.append('0')
    return resultat

def vvodPervoiStroki(a):
    a.str1 = vvodBitStroki(a, "Введите первую строку: ")
    if not proverka_pravilnosti(a, a.str1):
        print("Недопустимый символ в первой строке")
        exit()

def vvodVtoroiIzFile(a):
    try:
        with open("b.txt", "r") as file:
            a.str2 = list(file.read().strip())
    except FileNotFoundError:
        print("Файл b.txt не найден")
        exit()
    
    if not proverka_pravilnosti(a, a.str2):
        print("Недопустимый символ во второй строке")
        exit()

def obrabotka(a):
    a.addzero1 = 8 - len(a.str1)
    a.temp1 = buildup0(a, a.str1)
    
    a.addzero2 = 8 - len(a.str2)
    a.temp2 = buildup0(a, a.str2)
    
    a.resultat = vych_conjunction(a, a.temp1, a.temp2)
    a.resultat_strok = vivodBitStroki(a, a.resultat)

def vivodRezultatov(a):
    print("Первая строка: ", vivodBitStroki(a, a.temp1))
    print("Вторая строка: ", vivodBitStroki(a, a.temp2))
    print("Результат конъюнкции: ", a.resultat_strok)

def zapisVFile(a):
    with open("d.txt", "w") as file:
        file.write(a.resultat_strok)
    print("Результат записан в файл d.txt")

bitStr = BitString()

vvodPervoiStroki(bitStr)
vvodVtoroiIzFile(bitStr)
obrabotka(bitStr)
vivodRezultatov(bitStr)
zapisVFile(bitStr)
