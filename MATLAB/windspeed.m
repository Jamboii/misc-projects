%url = 'https://www.ncdc.noaa.gov/orders/qclcd/QCLCD201601.zip';
%filename = '201601.zip';
%websave(filename,url)
%download one zip file

%unzip(literally_anything.zip) %unzip one file

%Set a constant array of the six predetermined locations
location = ["SAN JUAN","G BUSH INTERCONTINENTAL AP/HOUSTON AP","CENTRAL PARK","DENVER INTERNATIONAL AIRPORT","KEY WEST INTERNATIONAL AIRPORT","SAN FRANCISCO INTERNATIONAL AIRPORT"];
speeds = cell(6,1); %Central hub for every wind speed 'AvgSpeed'
for i = 2016:2017
    for j = 1:12 %Double loop to go through every month of each year
        
        %DOWNLOAD PHASE
        url = sprintf('https://www.ncdc.noaa.gov/orders/qclcd/QCLCD%d%02d.zip',i,j);
        filename = sprintf('%d%02d.zip',i,j); %Set filename to current instance of loop
        if exist(filename, 'file') == 0 && ~(i == 2017 && j == 12) %if file not yet downloaded, and that we're not in december of 2017
            websave(filename,url) %download file
        end
        
        %UNZIP PHASE
        textDaily = sprintf('%d%02ddaily.txt',i,j); %set text file names to variables
        textStation = sprintf('%d%02dstation.txt',i,j);
        if (exist(textDaily,'file') == 0 || exist(textStation,'file') == 0) && ~(i == 2017 && j == 12) %if file doesn't exist
            unzip(filename) %unzip previously downloaded file
            delete *hourly.txt %Delete unncecessary files
            delete *monthly.txt
            delete *precip.txt
            delete *remarks.txt
        end
        
        %EXTRACT PHASE
        if ~(i == 2017 && j == 12)
            for k = 1:6 %go through each station
                openDaily = fopen(textDaily,'rt'); %open text files using variables declared earlier
                openStation = fopen(textStation,'rt');
                disp(location(k))
                avgSpeed = {}; %new celldata for every station
                disp('STATION SEARCH START')
                while true %STATION SEARCH // Continue going through every line of the file unless told otherwise
                    tline = fgetl(openStation); %take a line of the station text file
                    if strfind(tline, location(k)) > 0 %location string found on line
                        wbanID = tline(1:5); %save location id to variable
                        disp('AVGSPEED START')
                        while true %AVGSPEED SEARCH
                            strData = fgetl(openDaily); %take a line of the daily text file
                            if strfind(strData, wbanID) > 0 %station id found on line
                                split = strsplit(strData,','); %split data by its commas
                                avgSpeed = [avgSpeed,split{41}]; %41st value is AvgSpeed
                                disp(avgSpeed)
                            end
                            if ~ischar(strData) %empty line, break out of loop
                                disp('AVGSPEED BREAK')
                                break
                            end
                        end
                    end
                    if ~ischar(tline) %empty line
                        disp('STATION BREAK')
                        speeds{k} = [speeds{k},avgSpeed]; %ADD avgSpeed data of station to celldata
                        fclose(openStation);
                        fclose(openDaily);
                        break
                    end
                end
            end
        end
    end
end

%PLOT PHASE
x = 1:size(speeds{1},2); %x axis is the size of any of the stations' data
station1 = str2double(speeds{1}); %convert all celldata to doubles and assign different variables
station2 = str2double(speeds{2});
station3 = str2double(speeds{3});
station4 = str2double(speeds{4});
station5 = str2double(speeds{5});
station6 = str2double(speeds{6});

disp('PLOTTING')
plot(x,station1,'r',x,station2,'g',x,station3,'b',x,station4,'c',x,station5,'m',x,station6,'k','LineWidth',2),
xlabel('Day'), ylabel('Wind Speed'),
legend('San Juan, PR','Houston AP; Houston, TX','Central Park; New York, NY','Denver Int. AP; Denver, CO','Key West Int. AP; Key West, FL','San Francisco Int. AP; San Francisco, CA');
        
%11641 San Juan, PR
%12960 Houston AP, Houston, TX **DOWNTOWN HOUSTON DATA DOESN'T EXIST**
%94728 Central Park, New York, NY
%03017 Denver Int. Airport, Denver, CO
%12836 Key West Int. Airport, Key West, FL
%23234 San Francisco Int. Airport, San Fran., CA