#define encryption function
def encrypt(char, mac):
	hash = ''

	for part in mac:
		hash = hex(ord(char)) + hex(ord(part))

	return hash

def decrypt(char, mac):
	plain = ''

	for part in mac:
		plain = int(char) - hex(part)

	return plain

def main(direction):

	mac = ''
	f = open('mac_add.txt')
	mac = f.readline().strip()
	f.close()

	if(direction == 'en'):
		plaintext = open('message.txt','r')
		ciphertext = open('cipher.txt','w')

		for line in plaintext:
			print line
			for char in line:
				print encrypt(char, mac)
				ciphertext.write(encrypt(char,mac))

		plaintext.close()
		ciphertext.close()

	elif(direction == 'de'):
		ciphertext = open('cipher.txt','r')
		plaintext = open('message.txt','w')

		for line in ciphertext:
			for char in line:
				#decrypt with each element of MAC (Reverse?)
				for elem in mac:
					print decrypt(elem,mac)
					plaintext.write(decrypt(elem,mac))

		plaintext.close()
		ciphertext.close()

main('en')
