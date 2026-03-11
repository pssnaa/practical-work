.LC0:
        .string "I have generated a random number between 1 and 100."
.LC2:
        .string "Enter your guess: "
.LC3:
        .string "Too high! Try again."
.LC4:
        .string "Too low! Try again."
.LC5:
        .string "Congratulations! You guessed the correct number!"
main:
        push    rbp 
        mov     rbp, rsp
        sub     rsp, 16
        mov     edi, 0 
        call    time
        mov     edi, eax
        call    srand
        call    rand 
        movsx   rdx, eax
        imul    rdx, rdx, 1374389535
        shr     rdx, 32
        sar     edx, 5
        mov     ecx, eax
        sar     ecx, 31
        sub     edx, ecx
        imul    ecx, edx, 100
        sub     eax, ecx
        mov     edx, eax
        lea     eax, [rdx+1]
        mov     DWORD PTR [rbp-4], eax
        mov     DWORD PTR [rbp-8], 0    
        mov     esi, OFFSET FLAT:.LC0 
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        mov     esi, OFFSET FLAT:.LC1 
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        jmp     .L2
.L5:
        mov     esi, OFFSET FLAT:.LC2
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        lea     rax, [rbp-8]
        mov     rsi, rax
        mov     edi, OFFSET FLAT:std::cin
        call    std::istream::operator>>(int&)
        mov     eax, DWORD PTR [rbp-8]
        cmp     DWORD PTR [rbp-4], eax
        jge     .L3
        mov     esi, OFFSET FLAT:.LC3
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        jmp     .L2
.L3:
        mov     eax, DWORD PTR [rbp-8]
        cmp     DWORD PTR [rbp-4], eax
        jle     .L4
        mov     esi, OFFSET FLAT:.LC4
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        jmp     .L2
.L4:
        mov     esi, OFFSET FLAT:.LC5
        mov     edi, OFFSET FLAT:std::cout
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
.L2:
        mov     eax, DWORD PTR [rbp-8]
        cmp     DWORD PTR [rbp-4], eax
        jne     .L5
        mov     eax, 0
        leave
        ret