#Write a program to remove specific characters from a string.
#Input: Each line of input will be a string followed by a comma followed by characters that need to be scrubbed.
#Output: Print to standard output the scrubbed strings, one per line. Trim out any leading/trailing whitespaces if they occur.

class solution:
    def removeChars(st):
        s= st.split(",")
        print(s)
        sent = s[0]
        rem=s[1]
        sent=sent.lstrip()
        sent=sent.rstrip()
        print(sent)
        for each in rem:
            sent=sent.replace(each, "")
        return sent
    
    st="how are you,ab"
    print(removeChars(st))
