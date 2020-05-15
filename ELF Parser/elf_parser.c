#include "elf_parser.h"

typedef struct{
	char Key[3];
}KeyStruct;

char Buffer[1024*1024]={0};
char* ElfFileName= NULL;
char OutputFileName[30]="output.txt";
long size=0;
FILE * ElfFileDescriptor, * OutputFileDescriptor;
Elf32_Ehdr * Header = NULL;
Elf32_Shdr * SectionHeader = NULL;
Elf32_Shdr * StringTable = NULL;
Elf32_Phdr * ProgramHeader = NULL;
Elf32_Sym  * SybmolTable = NULL;

void ElfHeaderParser(void);
void SectionHeaderParser(void);
void ProgramHeaderParser(void);
void SymbolTableParser(void);

void main(int argc, char *argv[]){
	if(argv[1] != '\0'){
		ElfFileName = argv[1];
		//printf("%s", argv[1]);
		ElfFileDescriptor = fopen(ElfFileName, "rb"); // read mode
	}

	if (ElfFileDescriptor == NULL)
	{
		printf("Error while opening the file.\n");
	}else{
		
		/*get size of Elf File*/
		fseek(ElfFileDescriptor,0,SEEK_END);
		size = ftell(ElfFileDescriptor);
		fseek(ElfFileDescriptor,0,SEEK_SET);
		rewind(ElfFileDescriptor);
		
		/*save elf file content in buffer*/
		char ch = fgetc(ElfFileDescriptor);
		long long i=0;
		while (i != size)
		{
		Buffer[i]=ch;
		i++;
		ch = fgetc(ElfFileDescriptor);
		}
		//printf("%x\n",i);
		//fgets(Buffer, size, ElfFileDescriptor);
		KeyStruct * StringTemp = &Buffer[1];

		/*close elf file to open the output file*/
		fclose(ElfFileDescriptor);
		
		if(StringTemp->Key[0] == 'E' && StringTemp->Key[1] == 'L' && StringTemp->Key[2] == 'F'){
			/*pointing the header structure to the buffer containing the elf file*/
			Header = (Elf32_Ehdr *) &Buffer[0];
			/*open the output file that we will write the reversed elf file in*/
			OutputFileDescriptor = fopen(OutputFileName, "w+");
			
			/*printing the first section of elf file*/
			fprintf(OutputFileDescriptor,"ELF Header: \n");
			ElfHeaderParser();
	
			fprintf(OutputFileDescriptor,"\nSection Header: \n");
			SectionHeaderParser();
	
			fprintf(OutputFileDescriptor,"\nProgram Header: \n");
			ProgramHeaderParser();
			
			fprintf(OutputFileDescriptor,"\nSymbol Table: \n");
			SymbolTableParser();
		}else{
			printf("Invalid File Formate (ELF Files only are accepted)\n");
		}

	}
	fclose(OutputFileDescriptor);

}

void ElfHeaderParser(void){
	uint8_t Iterator=0;
	
	/*Printing Magic Number of Elf File*/
	fprintf(OutputFileDescriptor,"  Magic Number:\t ");
	for(Iterator=0;Iterator<EI_NIDENT;Iterator++){
		fprintf(OutputFileDescriptor,"%.02x ", Header->e_ident[Iterator]);
	}
	fprintf(OutputFileDescriptor,"\n");
	/*printing elf file class*/
	fprintf(OutputFileDescriptor,"  class \t\t\t\t\t\t: ");
	switch ( Header->e_ident[EI_CLASS]){
		case 0:
			fprintf(OutputFileDescriptor,"Invalid class\n");
		break;
		case 1:
			fprintf(OutputFileDescriptor,"ELF32\n");
		break;
		case 2:
			fprintf(OutputFileDescriptor,"ELF64\n");
		break;
		
	}
	/*elf file endianess*/
	fprintf(OutputFileDescriptor,"  Data \t\t\t\t\t\t\t: ");
	switch ( Header->e_ident[EI_DATA]){
		case 0:
			fprintf(OutputFileDescriptor,"Invalid data encoding\n");
		break;
		case 1:
			fprintf(OutputFileDescriptor,"2's complement, little endian\n");
		break;
		case 2:
			fprintf(OutputFileDescriptor,"2's complement, big endian\n");
		break;
		
	}
	/*elf file version*/
	fprintf(OutputFileDescriptor,"  Version \t\t\t\t\t\t: ");
	switch(Header->e_ident[EI_VERSION]){
		case 0:
			fprintf(OutputFileDescriptor,"0 (Invalid Version) \n");
		break;
		case 1:
			fprintf(OutputFileDescriptor,"1 (Current Version) \n");
		break;
		default:
			fprintf(OutputFileDescriptor,"  (Unknown) \n");
		break;
	}
	
	/*Os API Identification*/
	fprintf(OutputFileDescriptor,"  OS/ABI \t\t\t\t\t\t: ");
	switch(Header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			fprintf(OutputFileDescriptor,"UNIX System V ABI\n");
			break;

		case ELFOSABI_HPUX:
			fprintf(OutputFileDescriptor,"HP-UX\n");
			break;

		case ELFOSABI_NETBSD:
			fprintf(OutputFileDescriptor,"NetBSD\n");
			break;

		case ELFOSABI_LINUX:
			fprintf(OutputFileDescriptor,"Linux\n");
			break;

		case ELFOSABI_SOLARIS:
			fprintf(OutputFileDescriptor,"Sun Solaris\n");
			break;

		case ELFOSABI_AIX:
			fprintf(OutputFileDescriptor,"IBM AIX\n");
			break;

		case ELFOSABI_IRIX:
			fprintf(OutputFileDescriptor,"SGI Irix\n");
			break;

		case ELFOSABI_FREEBSD:
			fprintf(OutputFileDescriptor,"FreeBSD\n");
			break;

		case ELFOSABI_TRU64:
			fprintf(OutputFileDescriptor,"Compaq TRU64 UNIX\n");
			break;

		case ELFOSABI_MODESTO:
			fprintf(OutputFileDescriptor,"Novell Modesto\n");
			break;

		case ELFOSABI_OPENBSD:
			fprintf(OutputFileDescriptor,"OpenBSD\n");
			break;

		case ELFOSABI_ARM_AEABI:
			fprintf(OutputFileDescriptor,"ARM EABI\n");
			break;

		case ELFOSABI_ARM:
			fprintf(OutputFileDescriptor,"ARM\n");
			break;

		case ELFOSABI_STANDALONE:
			fprintf(OutputFileDescriptor,"Standalone (embedded) app\n");
			break;

		default:
			fprintf(OutputFileDescriptor,"Unknown \n");
			break;
	}
	
	/*ABI Version*/
	fprintf(OutputFileDescriptor,"  ABI Version \t\t\t\t\t: %x\n",Header->e_ident[EI_ABIVERSION]);

	/*Elf Type*/
	fprintf(OutputFileDescriptor,"  Type \t\t\t\t\t\t\t: ");
	switch(Header->e_type)
	{
		case ET_NONE:
			fprintf(OutputFileDescriptor,"N/A\n");
			break;

		case ET_REL:
			fprintf(OutputFileDescriptor,"Relocatable\n");
			break;

		case ET_EXEC:
			fprintf(OutputFileDescriptor,"Executable\n");
			break;

		case ET_DYN:
			fprintf(OutputFileDescriptor,"Shared Object\n");
			break;
			
		default:
			fprintf(OutputFileDescriptor,"Unknown\n");
			break;
	}
	
	/* ELF Machine-id */
	fprintf(OutputFileDescriptor,"  Machine \t\t\t\t\t\t:");
	switch(Header->e_machine)
	{
		case EM_NONE:
			fprintf(OutputFileDescriptor," None\n");
			break;

		case EM_ARM:
			fprintf(OutputFileDescriptor," ARM\n");
			break;


		default:
			fprintf(OutputFileDescriptor," 0x%x\n", Header->e_machine);
			break;
	}
	
	/*Entry point address*/
	fprintf(OutputFileDescriptor,"  Entry point address \t\t\t: 0x%x\n",Header->e_entry );

	/*Program Header address*/
	fprintf(OutputFileDescriptor,"  Program Header address \t\t: 0x%x\n",Header->e_phoff );

	/*Section Header address*/
	fprintf(OutputFileDescriptor,"  Section Header address \t\t: 0x%x\n",Header->e_shoff );

	/*Flags*/
	fprintf(OutputFileDescriptor,"  Flags \t\t\t\t\t\t: 0x%x\n",Header->e_flags );

	/*Elf Header Size (Bytes)*/
	fprintf(OutputFileDescriptor,"  Elf Header Size (Bytes)\t\t: %d\n",Header->e_ehsize );

	/*Program Header Size (Bytes)*/
	fprintf(OutputFileDescriptor,"  Program Header Size (Bytes)\t: %d\n",Header->e_phentsize );

	/*Number of program headers*/
	fprintf(OutputFileDescriptor,"  Number of program headers\t\t: %d\n",Header->e_phnum );

	/*Section Header Size (Bytes)*/
	fprintf(OutputFileDescriptor,"  Section Header Size (Bytes)\t: %d\n",Header->e_shentsize );

	/*Number of Section headers*/
	fprintf(OutputFileDescriptor,"  Number of Section headers\t\t: %d\n",Header->e_shnum );

	/*Section header string table index*/
	fprintf(OutputFileDescriptor,"  Section string table index\t: %d\n",Header->e_shstrndx );

}

void SectionHeaderParser(void){
	SectionHeader = (Elf32_Shdr *)(&Buffer[Header->e_shoff]);
	StringTable = (&SectionHeader[Header->e_shstrndx]);
	char *StringTablePtr = NULL;
	
	for(int i=0;i<Header->e_shnum;i++){
		 if (SectionHeader[i].sh_type == SHT_STRTAB){
			 StringTablePtr = &Buffer[SectionHeader[20].sh_offset];
		 }
	}
	/*for(int i=0;i<Header->e_shnum;i++){
		 printf("%2d: %x '%s'\n", i, SectionHeader[i].sh_name,StringTablePtr + SectionHeader[i].sh_name);
	}*/
	
	fprintf(OutputFileDescriptor,"  \t\tName\t\t\tType\t\tFlags\t\t\tAddress\t\t\tOffset\t\t\t\tSize\t\t\tLink\t\tInfo\t\tAllignment\n");
	

	
	for(long i=0;i< Header->e_shnum ;i++){

		fprintf(OutputFileDescriptor,"  %15s\t\t",StringTablePtr + SectionHeader[i].sh_name );
		switch((SectionHeader+i)-> sh_type){
			case 0:
			fprintf(OutputFileDescriptor,"  NULL    \t\t");
			break;
			case 1:
			fprintf(OutputFileDescriptor,"  PROGBITS\t\t");
			break;
			case 2:
			fprintf(OutputFileDescriptor,"  SYMTAB  \t\t");
			break;
			case 3:
			fprintf(OutputFileDescriptor,"  STRTAB  \t\t");
			break;
			default:
			fprintf(OutputFileDescriptor,"  TODO\t\t\t");
			break;
		}
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (SectionHeader+i)-> sh_flags) );
		fprintf(OutputFileDescriptor,"0x%.08x\t\t",( (SectionHeader+i)-> sh_addr));
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (SectionHeader+i)-> sh_offset));
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (SectionHeader+i)-> sh_size));
		fprintf(OutputFileDescriptor,"0x%.02x\t\t",( (SectionHeader+i)-> sh_link));
		fprintf(OutputFileDescriptor,"0x%.04x\t\t",( (SectionHeader+i)-> sh_info));
		fprintf(OutputFileDescriptor,"0x%.02x\n",( 	 (SectionHeader+i)-> sh_addralign));
	
	}
}

void ProgramHeaderParser(void){
	ProgramHeader = (Elf32_Phdr *)(&Buffer[0] + Header->e_phoff);
	fprintf(OutputFileDescriptor,"  Type\t\t  Offset\t\tVirtAddr\t\tPhysAddr\t\tFileSiz\t\t\tMemSiz\t\t\tFlg\t\t\t\tAlign\n");

	for(int i=0;i<Header->e_phnum;i++){
		switch((ProgramHeader+i)-> p_type){
			case 0:
			fprintf(OutputFileDescriptor,"  NULL\t\t");
			break;
			case 1:
			fprintf(OutputFileDescriptor,"  LOAD\t\t");
			break;
			case 2:
			fprintf(OutputFileDescriptor,"  DYNAMIC\t\t");
			break;
			case 3:
			fprintf(OutputFileDescriptor,"  INTERP\t\t");
			break;
			
		}
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (ProgramHeader+i)-> p_offset) );
		fprintf(OutputFileDescriptor,"0x%.08x\t\t",( (ProgramHeader+i)-> p_vaddr));
		fprintf(OutputFileDescriptor,"0x%.08x\t\t",( (ProgramHeader+i)-> p_paddr));
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (ProgramHeader+i)-> p_filesz));
		fprintf(OutputFileDescriptor,"0x%.06x\t\t",( (ProgramHeader+i)-> p_memsz));
		fprintf(OutputFileDescriptor,"0x%.08x\t\t",( (ProgramHeader+i)-> p_flags));
		fprintf(OutputFileDescriptor,"0x%.06x\n",( (ProgramHeader+i)-> p_align));

	}
	
}

void SymbolTableParser(void){
	SectionHeader = (Elf32_Shdr *)(&Buffer[Header->e_shoff]);
	long NumOfSybmols = 0;
	short StringTableIDX=0;
	for(int i=0;i<Header->e_shnum;i++){
		 if (SectionHeader[i].sh_type == SHT_SYMTAB){
			 //SybmolTable = (Elf32_Sym *)&SectionHeader[i].sh_offset;
			 SybmolTable = (Elf32_Sym *)&Buffer[SectionHeader[i].sh_offset];
			 NumOfSybmols = SectionHeader[i].sh_size / sizeof(Elf32_Sym);
			 printf("size of sybmol table %x \n", NumOfSybmols);
		 }
	}
	
	StringTable = (&SectionHeader[Header->e_shstrndx]);
	char *StringTablePtr = NULL;
	
	for(int i=0;i<Header->e_shnum;i++){
		 if (SectionHeader[i].sh_type == SHT_STRTAB){
			 StringTableIDX =i;
			 StringTablePtr = &Buffer[SectionHeader[i].sh_offset];
		 }
	}
	
	fprintf(OutputFileDescriptor, "  Num:\t\tValue\t\t\tSize\t\tType\t\t\tBind\t\tVis\t\t\t\tNdx\t\t\t\tName\n");
	for (int i=0;i<NumOfSybmols;i++){
		fprintf(OutputFileDescriptor, "  [%.03d]\t\t",i);
		fprintf(OutputFileDescriptor, "%.08x\t\t",(SybmolTable+i)->st_value);
		fprintf(OutputFileDescriptor, "%.04x\t\t",(SybmolTable+i)->st_size);
		switch( ((SybmolTable+i)->st_info)&0x0F ){
			case STT_NOTYPE:
			fprintf(OutputFileDescriptor," NOTYPE ");
			break;		
			case STT_OBJECT:		
			fprintf(OutputFileDescriptor," OBJECT ");
			break;		
			case STT_FUNC:		
			fprintf(OutputFileDescriptor," FUNC   ");
			break;		
			case STT_SECTION:		
			fprintf(OutputFileDescriptor," SECTION");
			break;		
			case STT_FILE:		
			fprintf(OutputFileDescriptor," FILE	  ");
			break;		
			case STT_COMMON:		
			fprintf(OutputFileDescriptor," COMMON ");
			break;		
			case STT_TLS:		
			fprintf(OutputFileDescriptor," ThreadLocal	");
			break;
			case STT_NUM:
			fprintf(OutputFileDescriptor," NumOfDefTypes");
			break;
			case STT_LOOS:
			fprintf(OutputFileDescriptor," OS-specificStart");
			break;
			case STT_LOPROC:
			fprintf(OutputFileDescriptor," processor-specificStart	");
			break;
			/*case STT_GNU_IFUNC: //same value as STT_LOOS
			fprintf(OutputFileDescriptor," IndirectFUNC");
			break;*/
			case STT_HIOS:
			fprintf(OutputFileDescriptor," OS-specificEnd");
			break;
			case STT_HIPROC:
			fprintf(OutputFileDescriptor," processor-specificEnd");
			break;
		}
		fprintf(OutputFileDescriptor, "\t\t");
		switch( ((((SybmolTable+i)->st_info)&0xF0)>>4) ){
			case STB_LOCAL:
			fprintf(OutputFileDescriptor," LOCAL ");
			break;
			case STB_GLOBAL:
			fprintf(OutputFileDescriptor," GLOBAL");
			break;			
			case STB_WEAK:
			fprintf(OutputFileDescriptor," WEAK  ");
			break;			
			case STB_NUM:
			fprintf(OutputFileDescriptor," NumOfDefTypes");
			break;			
			case STB_LOOS:
			fprintf(OutputFileDescriptor," OS-specificStart");
			break;			
			case STB_HIOS:
			fprintf(OutputFileDescriptor," OS-specificEnd");
			break;			
			case STB_LOPROC:
			fprintf(OutputFileDescriptor," processor-specificStart");
			break;			
			case STB_HIPROC:
			fprintf(OutputFileDescriptor," processor-specificEnd");
			break;
		}
		fprintf(OutputFileDescriptor, "\t\t" );
		switch( (SybmolTable+i)->st_other ){
			case STV_DEFAULT:
			fprintf(OutputFileDescriptor," DEFAULT");
			break;			
			case STV_INTERNAL:
			fprintf(OutputFileDescriptor," INTERNAL");
			break;			
			case STV_HIDDEN:
			fprintf(OutputFileDescriptor," HIDDEN ");
			break;			
			case STV_PROTECTED:
			fprintf(OutputFileDescriptor," PROTECTED");
			break;
		}
		fprintf(OutputFileDescriptor, "\t\t");
		fprintf(OutputFileDescriptor, "%.06x\t\t",(SybmolTable+i)->st_shndx);
		fprintf(OutputFileDescriptor, "%s\n", StringTablePtr + SybmolTable[i].st_name);
	}
}