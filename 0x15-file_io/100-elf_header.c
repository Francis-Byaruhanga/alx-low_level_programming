#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "main.h"

void check_elf(unsigned char *e_ident);
void print_info(Elf64_Ehdr *header);

void close_elf(int elf);

/**
 * main - Entry point of the program, displays ELF header information.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Description: Opens an ELF file, reads its header, and displays information
 * from the ELF header. Exits with code 98 if there are errors.
 *
 * Return: 0 on Success.
 */
int main(int argc, char *argv[])
{
	int o;
	Elf64_Ehdr header;
	ssize_t r;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	o = open(argv[1], O_RDONLY);

	if (o == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		return (98);
	}

	r = read(o, &header, sizeof(Elf64_Ehdr));

	if (r == -1)
	{
		close_elf(o);
		fprintf(stderr, "Error: `%s`: No such file\n", argv[1]);
		return (98);
	}

	check_elf(header.e_ident);
	printf("ELF Header:\n");
	print_info(&header);

	close_elf(o);
	return (0);
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, it exits with code 98
 * and displays an erro message to stderr.
 */
void check_elf(unsigned char *e_ident)
{
	if (memcmp(e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_info - Prints information from the ELF header.
 * @header: A pointer to the ELF structure.
 *
 * Description: Prints the magic numbers, class, data, version,
 * OS/ABI, type and entry point from the ELF header.
 */
void print_info(Elf64_Ehdr *header)
{
	int i;

	printf(" Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf(" Class: ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF3232\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}

	printf(" Data: ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
	}

	printf(" Version: %d", header->e_ident[EI_VERSION]);
	switch (header->e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}

	printf(" OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}

	printf(" ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);

	printf(" Type: ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", header->e_type);
	}

	printf(" Entry point address: %#lx\n", header->e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: Closes the ELF file, and if it fails, it
 * exits with code 98, and displays an error message to stderr.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}
