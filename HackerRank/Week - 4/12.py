def decodeHuff(root, s):
    current = root
    result = ''
    for code in s:
        if int(code) == 0:
            current = current.left
        else:
            current = current.right
        if current.left == None and current.right == None:
            result += current.data
            current = root
    print(result)
