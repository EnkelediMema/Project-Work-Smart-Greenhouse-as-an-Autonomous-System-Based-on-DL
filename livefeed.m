clear all 
the_camera = webcam;
the_network = googlenet;
required_input_size = the_network.Layers(1).InputSize(1:2)

h = figure;

while ishandle(h)
single_Image = snapshot(the_camera);
image(single_Image)
single_Image = imresize(single_Image, required_input_size);
[predicted_Item,probability] = classify(the_network, single_Image);
title({char(predicted_Item), num2str(max(probability),2)});
drawnow
end