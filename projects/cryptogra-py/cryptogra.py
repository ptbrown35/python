
def encode(key, string):
    encoded_chars = []
    for i in range(len(string)):
        key_c = key[i % len(key)]
        encoded_c = chr(ord(string[i]) + ord(key_c) % 128)
        encoded_chars.append(encoded_c)
    encoded_string = "".join(encoded_chars)
    return encoded_string


def decode(key, string):
    decoded_chars = []
    for i in range(len(string)):
        key_c = key[i % len(key)]
        decoded_c = chr(ord(string[i]) - ord(key_c) % 128)
        decoded_chars.append(decoded_c)
    decoded_string = "".join(decoded_chars)
    return decoded_string


key = "temppwd"
message = "Message..."
print("Message: {}".format(message))
message_enc = encode(key, message)
print("Encrytped Message: {}".format(message_enc))
message_dec = decode(key, message_enc)
print("Decrytped Message: {}".format(message_dec))
