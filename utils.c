int check_cmd(char **correct, const char *cmd, char **envp) 
{
    char *path_env;
    char **path_list;
    char *file_path;
    int ret;
    int i;
    // Verificación de argumentos
    if (!correct || !cmd || !envp) 
        return -1;
   
    path_env = find_path(env);
    if (!path_env) 
        return -1;
    path_list = ft_split(path_env, ':');
    if (!path_list) 
        return -1;
    // Verificar si el archivo existe y es ejecutable
    file_path = NULL;
    ret = -1;
    i = 0;
    while (path_list[i] && ret == -1)
    {
        file_path = ft_strjoin(path_list[i], "/");
        file_path = ft_strjoin(file_path, cmd);
        ret = access(file_path, X_OK);
        i++;
    }
    if (ret == -1) 
    {
        free(file_path);
        file_path = NULL;
    }
    // Liberar memoria
    free(path_list);
    // Asignar el valor de file_path a correct y retornar
    *correct = file_path;
    return ret;
}
