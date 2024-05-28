% model declaration and running it for 5 secs
mdl = "final_project";
set_param(mdl, 'SimulationCommand', 'start')
pause(30)
toWksData = simout1;

%data manipulation of the simulink data
charArray = char(toWksData);
cellArray = cellstr(charArray);
for row = 1:size(cellArray, 1)
    for col = 1:size(cellArray, 2)
        splitString = strsplit(cellArray{row, col}, ',');
        splitString{end} = strrep(splitString{end}, ';', '');
        cellArray{row, col} = splitString;
    end
end

%data saving csv
T = cell2table(cellArray);
filename = 'obstacleLog.csv';
writetable(T, filename);
existingFileName = 'obstacleLog.csv';
T = readtable(existingFileName);
newColumnNames = {'Angle', 'Distance', 'Status'};
T.Properties.VariableNames = newColumnNames;
outputFileName = 'obstacleLog.csv';
writetable(T, outputFileName);

