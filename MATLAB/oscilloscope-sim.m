% Define time-related parameters.
period_T = 0.001;
delta_t = period_T/100; % sampling time
number_data_points = period_T/delta_t; % Define the waveform.
Vmax = 4;
Vmin = 0;
Vpp = Vmax - Vmin; % peak-to-peak
Vamp = Vpp/2; % amplitude
Vdc_offset = (Vmax - Vmin)/2 + Vmin; % dc offset
% Define frequency in Hz and rad/s.
f = 60; % in Hz
dcycles = [20,50,80];
p = 1;
% Create waveform using for-loop.
for i = 1:4 % For the 4 graphs: sawtooth(60Hz) and square(60Hz,600Hz,6000Hz)
    for j = 1:3
        omega = 2*pi*f; % in rad/s
        for k = 1:number_data_points
            t(k) = k*delta_t;
            % Define kth element of voltage array.
            if (i > 1)
                v(k) = Vamp*square(omega*t(k),dcycles(j)) + Vdc_offset;
            else
                v(k) = Vamp*sawtooth(omega*t(k)) + Vdc_offset;
            end
            
        end
        if (i > 1)
            rms = sqrt(mean(v.^2));
            fprintf('SQUARE WAVE %d Hz, DUTY CYCLE %d : RMS = %d\n',f,dcycles(j),rms)
            figure(2)
            subplot(3,3,p);
            plot(v)
            title(sprintf('Square %d Hz, Duty Cycle %d',f,dcycles(j)))
            p = p + 1;
        else
            rms = sqrt(mean(v.^2));
            fprintf('SAWTOOTH WAVE %d Hz : RMS = %d\n',f,rms)
            figure(1)
            plot(v)
            title('Sawtooth 60Hz')
            break
        end
    end
    if (i > 1)
        f = f*10;
    end
end