figure;
axis equal;
hold on;

file = fopen('CameraRays.txt');
C = fscanf(file, '%f %f %f', [3 Inf]);
C = C';

X = C(:, 1);
Y = C(:, 2);
Z = C(:, 3);

startX = X(1);
startY = Y(1);
startZ = Z(1);

for i=2:length(X)
    plot3([startX X(i)], [startY Y(i)], [startZ Z(i)], '-b');
end