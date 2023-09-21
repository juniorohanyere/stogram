pcb_t create_pcb(uint16_t id, uint16_t pid, uint16_t ppid, uint16_t prio,
	uint16_t pcount, int pstate, int fd, char *pname, char *reg,
	meminfo_t *meminfo);
{
	pcb_t *pcb;

	pcb = malloc(sizeof(pcb_t));
	if (pcb == NULL)
		return (NULL);

	pcb->id = id;
	pcb->pid = pid;
	pcb->ppid = ppid;
	pcb->prio = prio;
	pcb->pcount = pcount;
	pcb->pstate = pstate;

	pcb->fd = fd;

	pcb->pname = strdup(pname);
	pcb->reg = strdup(reg);
	if (pcb->pname == NULL || pcb->reg == NULL)
		return (NULL);

	pcb->meminfo = malloc(sizeof(meminfo_t));
	if (pcb->meminfo == NULL)
		return (NULL);
	pcb->meminfo = meminfo;

	return (pcb);
}

char **pcb_info(pcb_t *pcb)
{
	char **info;

	info = malloc(sizeof(char *) * 11);
	if (pcb == NULL || info == NULL)
		return (NULL);

	strcpy(info[0], (char *)&pcb->id);
	strcpy(info[1], (char *)&pcb->pid);
	strcpy(info[2], (char *)&pcb->ppid);
	strcpy(info[3], (char *)&pcb->prio);
	strcpy(info[4], (char *)&pcb->pcount);
	strcpy(info[5], (char *)&pcb->pstate);
	strcpy(info[6], (char *)&pcb->fd);
	strcpy(info[7], pcb->pname);
	strcpy(info[8], pcb->reg);

