from math import ceil

# в окружность палочки помещается N букв
N = 3

"""
шифруем текст
разносим текст в матрицу N * M где N - строки = число букв помещающихся в окружность
M - столбцы = длина строки / N и округленная вверх до целого
В матрицу записываем текст по строкам, результат выводим по столбцам
"""
def encode(text):
    # получаем количество столбцов
    M = ceil(float(len(text)) / N)
    # создаем матрицу N * M
    matrix = [[None] * M for _ in range(N)]
    # заполняем матрицу текстом по строкам
    for i in range(N):
        for j in range(M):
            index = M * i + j
            if index < len(text):
                matrix[i][j] = text[index]
    # читаем матрицу по столбцам => получаем код
    code = ""
    for j in range(M):
        for i in range(N):
            if matrix[i][j] != None:
                code = code + matrix[i][j]
            else:
                code = code + '_' 
    return code

"""
расшифровываем код
разносим код в матрицу N * M где N - строки = число букв помещающихся в окружность
M - столбцы = длина строки / N и округленная вверх до целого
В матрицу записываем код по столбцам, декодированный текст вычитываем по строкам
"""
def decode(code):
    # получаем количество столбцов
    M = ceil(float(len(code)) / N)
    # создаем матрицу N * M
    matrix = [[None] * M for _ in range(N)]
    # загоняем в матрицу код по столбцам
    for j in range(M):
        for i in range(N):
            index = N * j + i
            if code[index] == '_':
                continue
            if index < len(code):
                matrix[i][j] = code[index]       
    text = "" 
    # вычитываем из матрицы текст по строкам   
    for i in range(N):
        for j in range(M):
            if matrix[i][j] != None:
                text = text + matrix[i][j]
    return text

mes = input("Введите сообщение для шифрования: ")
encode_mes = encode(mes)
print("Зашифрованное сообщение:", encode_mes)

decode_mes = decode(encode_mes)
print("Расшифрованное сообщение:", decode_mes)

