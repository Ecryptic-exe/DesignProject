from inference.models.utils import get_roboflow_model
import cv2

# Set the model name and version
model_name = "design-project-l6fmn"
model_version = "2"

# Open the default camera (usually the built-in webcam)
cap = cv2.VideoCapture(0)

# Check if the webcam is opened successfully
if not cap.isOpened():
    print("Error: Could not open camera.")
    exit()

# Get the Roboflow model
model = get_roboflow_model(
    model_id="{}/{}".format(model_name, model_version),
    api_key="jf0Up8otdUB1r0ua9mLG"
)

# Set the desired frame width and height
desired_width = 800
desired_height = 600

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

    # If the frame was read successfully, resize and display it
    if ret:
        # Resize the frame
        frame = cv2.resize(frame, (desired_width, desired_height))

        # Run inference on the resized frame
        results = model.infer(image=frame,
                               confidence=0.5,
                               iou_threshold=0.5)

        # Set up variables for drawing bounding boxes and labels
        COLOR_YELLOW = (255, 255, 0)
        COLOR_WHITE = (255, 255, 255)
        THICKNESS = 10
        TEXT_SIZE = 1.5
        TEXT_FONT = cv2.FONT_HERSHEY_SIMPLEX

        # Iterate over the results and draw bounding boxes and labels
        for i, result in enumerate(results):
            if result:
                bounding_box = result[0]

                x0, y0, x1, y1 = map(int, bounding_box[:4])

                # Calculate confidence percentage
                confidence_percentage = int(bounding_box[4] * 100)

                cv2.rectangle(frame, (x0, y0), (x1, y1), COLOR_YELLOW, THICKNESS)
                label = ""
                if i == 0:
                    label = "Dead Plant"
                elif i == 1:
                    label = "flowers"
                elif i == 2:
                    label = "plants"
                cv2.putText(frame, f"{label}: {confidence_percentage}%", (x0, y0 - 10), TEXT_FONT, TEXT_SIZE,
                            COLOR_WHITE, 2)

        # Display the resulting resized frame
        cv2.imshow('Webcam Feed', frame)

        # Add a GUI button to quit the video window
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

# When everything is done, release the capture and destroy all windows
cap.release()
cv2.destroyAllWindows()
