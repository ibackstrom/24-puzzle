# 24 puzzle
My attemp to execute string brute force with three languages (python, ruby, cpp)

Use each of the numbers 1, 3, 4, and 6 exactly once with any of the four basic math operations (addition, subtraction, multiplication, and division) to total 24. Each number must be used once and only once, and you may define the order of operations; for example, 3 * (4 + 6) + 1 = 31 is valid, however incorrect, since it doesn't total 24.

I was never into a leet coding. But sometimes I really enjoy some small puzzles. Recently I was reading a book and found following puzzle.

Use 1, 3, 4, 6 exactly once with +, −, ×, ÷ and parentheses to make 24.

It's quite obvious that brute force is the only practical solution. So I was wondering how hard it will be to make a program using different languages and libs.

Of course, the first thing that came to my mind is eval() function in python. I just make all variations of string and run it as a command.

During the adventure I faced some problem with generating brackets pattern. But overall python lib itertools was the main helper.

CPP was challenging because of memory. WIth help of Senior Grok I found out that I can create templates during compilation (which is awesome and thanks to constexpr).

The library TinyExpr helped a lot.

I think pure c code with all memoty allocations will took around 200 lines. It would be solid, fast and robust but It's overkill for sure.

What was surprise is Ruby. After recent podcust with DHH I wanted to put my hands on. And it performed well. Not good documentation though.

Ruby was only 28 lines of readable code.

**Run time:**  
Python: 0.107 ms  
Ruby: 0.115 ms  
CPP: 0.026 ms

*don't forget to compile tinyexpr before running cpp code


Tree for recursive generating bracket template:


