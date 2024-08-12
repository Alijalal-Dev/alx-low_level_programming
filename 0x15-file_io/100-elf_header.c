#include "main.h"
#include <elf.h>

/**
 * p_magic - prints ELF magic bytes
 * @header: ELF header
 */
void p_magic(Elf64_Ehdr header)
{
	int i = 0;

	printf("  Magic:   ");
	for (; i < EI_NIDENT; i++)
		printf("%02x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * p_class - prints ELF class
 * @header: ELF header
 */
void p_class(Elf64_Ehdr header)
{
	printf("  Class:                             ");
	switch (header.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
		default:
			printf("<unknown: %x>", header.e_ident[EI_CLASS]);
	}
	printf("\n");
}

/**
 * p_data - prints ELF data
 * @header: ELF header
 */
void p_data(Elf64_Ehdr header)
{
	printf("  Data:                              ");
	switch (header.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * p_version - prints ELF version
 * @header: ELF header
 */
void p_version(Elf64_Ehdr header)
{
	printf("  Version:                           %d%s\n",
		header.e_ident[EI_VERSION],
		header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
}

/**
 * p_reste_osabi - prints the reste of ELF os/abi
 * @header: ELF header
 */
void p_reste_osabi(Elf64_Ehdr header)
{
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - Open BSD\n");
			break;
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto\n");
			break;
		default:
			printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	}
}

/**
 * p_osabi - prints ELF os/abi
 * @header: ELF header
 */
void p_osabi(Elf64_Ehdr header)
{
	printf("  OS/ABI:                            ");
	switch (header.e_ident[EI_OSABI])
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
		default:
			p_reste_osabi(header);
			break;
	}
}

/**
 * p_abi_version - prints ELF ABI version
 * @header: ELF header
 */
void p_abi_version(Elf64_Ehdr header)
{
	printf("  ABI Version:                       %d\n",
			header.e_ident[EI_ABIVERSION]);
}

/**
 * p_type - prints ELF type
 * @header: ELF header
 */
void p_type(Elf64_Ehdr header)
{
	char *ptr = (char *)&header.e_type;
	int i = 0;

	printf("  Type:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		i = 1;
	switch (ptr[i])
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", ptr[i]);
	}
}

/**
 * p_entry - prints ELF entry point address
 * @header: ELF header
 */
void p_entry(Elf64_Ehdr header)
{
	int i = 0, size = 0;
	unsigned char *ptr = (unsigned char *)&header.e_entry;

	printf("  Entry point address:               0x");
	if (header.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		i = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[i])
			i--;
		printf("%x", ptr[i--]);
		for (; i >= 0; i--)
			printf("%02x", ptr[i]);
		printf("\n");
	}
	else
	{
		size = header.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[i])
			i++;
		printf("%x", ptr[i++]);
		for (; i <= size ; i++)
			printf("%02x", ptr[i]);
		printf("\n");
	}
}

/**
 * main - entry point
 * @ac: arguments count
 * @av: arguments vectors
 * Return: 1 (Success)
 */
int main(int ac, char **av)
{
	int file_descriptor;
	Elf64_Ehdr header;
	ssize_t bytes;

	if (ac != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_header\n"), exit(98);
	file_descriptor = open(av[1], O_RDONLY);
	if (file_descriptor == -1)
		dprintf(STDERR_FILENO, "Can't read file: %s\n", av[1]), exit(98);
	bytes = read(file_descriptor, &header, sizeof(header));
	if (bytes < 1 || bytes != sizeof(header))
		dprintf(STDERR_FILENO, "Can't read file: %s\n", av[1]), exit(98);
	if (header.e_ident[0] == 127 &&
			header.e_ident[1] == 'E' &&
			header.e_ident[2] == 'L' &&
			header.e_ident[3] == 'F')
		printf("ELF Header:\n");
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", av[1]), exit(98);
	p_magic(header);
	p_class(header);
	p_data(header);
	p_version(header);
	p_osabi(header);
	p_abi_version(header);
	p_type(header);
	p_entry(header);
	if (close(file_descriptor))
		dprintf(STDERR_FILENO, "Error closing file description: %d\n",
				file_descriptor), exit(98);
	return (EXIT_SUCCESS);
}
