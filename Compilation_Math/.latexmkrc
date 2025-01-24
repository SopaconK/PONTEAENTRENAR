# Usar biber para la bibliografía
$bibtex_use = 2; # Habilitar biber en lugar de bibtex

# Definir comandos para Asymptote (asy)
add_cus_dep('asy', 'pdf', 0, 'run_asy');
sub run_asy {
    my ($base_name, $path) = @_;
    system("asy $base_name.asy");
}

# Asegurarse de que se ejecute pdflatex en modo sin interrupciones
$pdf_mode = 1;
$pdflatex = 'pdflatex -interaction=nonstopmode -synctex=1 %O %S';

# Ejecutar biber automáticamente si se necesita
$biber = 'biber %O %S';

# Opcional: especificar el número de compilaciones automáticas
$max_repeat = 2; # Para bibliografías complicadas
