clear all;
close all;

A = importdata("resultats.dat");
B = A / sum(A(1,:)) * 100;
C = flip(cumsum(flip(B')', 2)')';
fig = figure();
%semilogx(1:size(B, 1), B, "linewidth", 2, "linestyle", "-");
fill([1, 1:size(C, 1), size(C, 1)], [0, C(:,1)', 0], "g", [1, 1:size(C, 1), size(C, 1)], [0, C(:,2)', 0], "r", [1, 1:size(C, 1), size(C, 1)], [0, C(:,3)', 0], "y", [1, 1:size(C, 1), size(C, 1)], [0, C(:,4)', 0], "k");
set (gca, "xscale", "log");
title("Simulation du COVID-19 avec le modèle SIR");
xlim([1, size(A, 1)]);
ylim([0, 100]);
xlabel("Temps écoulé depuis le début de l'épidémie (en jours)");
ylabel("Pourcentage de la population");
h = legend("S", "I", "R", "M");
legend (h, "location", "northeastoutside");
%set(h, "fontsize", 20);
saveas(fig, "plot_resultats.png");
