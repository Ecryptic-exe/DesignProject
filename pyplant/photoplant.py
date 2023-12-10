from inference.models.utils import get_roboflow_model
import cv2

# Image path
image_path = "shutterstock_152500682-768x508.jpg"

# Roboflow model
model_name = "design-project-l6fmn"
model_version = "2"

# Get Roboflow face model (this will fetch the model from Roboflow)
model = get_roboflow_model(
    model_id="{}/{}".format(model_name, model_version),
    # Replace ROBOFLOW_API_KEY with your Roboflow API Key
    api_key="jf0Up8otdUB1r0ua9mLG"
)

# Load image with OpenCV
frame = cv2.imread(image_path)

# Inference image to find faces
results = model.infer(image=frame, confidence=0.5, iou_threshold=0.5)

# Plot image with face bounding box (using OpenCV)
if results[0]:
    bounding_box = results[0][0]
    confidence = bounding_box[4] * 100  # Confidence is at index 4 in the results
    print(f"Confidence: {confidence:.2f}%")

    x0, y0, x1, y1 = map(int, bounding_box[:4])
    
    cv2.rectangle(frame, (x0, y0), (x1, y1), (255, 255, 0), 10)
    cv2.putText(frame, f"Confidence: {confidence:.2f}%", (x0, y0 - 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    cv2.putText(frame, "Dead Plant", (x0, y0 - 10), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

# Show image
cv2.imshow('Image Frame', frame)
cv2.waitKey(0)  # waits until a key is pressed
cv2.destroyAllWindows()  # destroys the window showing the image
