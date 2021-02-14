braces = {
      '{' : '}',
      '[' : ']',
      '(' : ')',
    }
# What the heck, is there a doc for this?
inverted_braces = {v:k for k,v in braces.items()}
print(braces)
print(inverted_braces)