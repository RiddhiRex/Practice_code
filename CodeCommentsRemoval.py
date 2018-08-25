sample input:
public class HelloWorld {
    // This program will print "Hello, World"
    public static void main(String[] args) {
        System.out.println("Hello/*, World*/"); // A single line comment
        /* A sample comment
           spanning multiple
           lines*/
    /*}
}
Sample Output:
public class HelloWorld {

    public static void main(String[] args) {
        System.out.println("Hello ");
         


    /*}
}
def commentsRemoval(inputText):
  #inputText = ["nnn nnnnn //aaaaa", "rrrrrr /* asdsdf */ nnnnnnn", "mmm /* ssssss", "qqqqqqqqqqqqq */ qwe", "asd /* asd"]
  result = [""]* len(inputText)
  BlockCmt = False
  i = 0 
  for line in inputText:
      if "/*" in line:
          BlockCmt = True
          ln = i
          pt = line.find("/*")

      if BlockCmt == True and "*/" in line:
          BlockCmt = False
          for x in range(ln, i):
              result[x]="\n"
          if("/*" in line):
              line = line[0:line.find("/*")]+line[line.find("*/")+2: ]
          else:
              result[ln]= inputText[ln][0:pt]
              line = line[line.find("*/")+2: ]

      if "//" in line:
          line = line[0:line.find("//")]

      result[i] = line
      i=i+1

  return "\n".join(result)
        

    
