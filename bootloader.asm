BITS 16             ; Set the assembler to 16-bit mode

start:
    ; Set up the segment registers
    xor ax, ax      ; Clear AX
    mov ds, ax      ; Set DS to 0
    mov es, ax      ; Set ES to 0

    ; Print a message to the screen
    mov si, message ; Load the message string address into SI
    call print      ; Call the print function

    ; Hang the CPU
    cli             ; Disable interrupts
    hlt             ; Halt the CPU

print:
    ; Print a null-terminated string at the address in SI
    .print_loop:
        lodsb       ; Load the byte at SI into AL and increment SI
        or al, al   ; Check if AL is zero (end of string)
        jz .print_done ; If zero, we're done
        mov ah, 0x0E ; BIOS teletype function
        mov bh, 0x00 ; Display page 0
        mov bl, 0x07 ; White text on black background
        int 0x10    ; Call BIOS interrupt for teletype
        jmp .print_loop ; Continue printing
    .print_done:
        ret         ; Return from the print function

message db "Hello, world!", 0x0D, 0x0A, 0 ; Null-terminated string with newline

times 510 - ($ - $$) db 0 ; Fill the rest of the boot sector with zeros
dw 0xAA55                   ; Boot signature
