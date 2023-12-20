from roboflow import Roboflow
import cv2 as cv


rf = Roboflow(api_key="jf0Up8otdUB1r0ua9mLG")
project = rf.workspace().project("design-project-l6fmn")
model = project.version(3).model

f = cv.VideoCapture(0)

while(f.isOpened()):
    ret, frame = f.read()
    if ret == True:
        cv.imwrite('temp.jpg', frame)
        predictions = model.predict('temp.jpg')
        predictions_json = predictions.json()

        for bounding_box in predictions_json["predictions"]:
            x0 = int(bounding_box['x'] - bounding_box['width'] / 2)
            x1 = int(bounding_box['x'] + bounding_box['width'] / 2)
            y0 = int(bounding_box['y'] - bounding_box['height'] / 2)
            y1 = int(bounding_box['y'] + bounding_box['height'] / 2)
            class_name = bounding_box['class']
            confidence_score = bounding_box['confidence']
            
            cv.rectangle(frame, (x0, y0), (x1, y1), (255, 0, 0), 2)
            cv.putText(frame, f"{class_name}: {confidence_score:.2f}", (x0, y0 - 10), cv.FONT_HERSHEY_SIMPLEX, 0.9, (255, 0, 0), 2)

            detection_results = bounding_box
            class_and_confidence = (class_name, confidence_score)
            print(class_and_confidence, '\n')

        cv.imshow('Frame', frame)

    if cv.waitKey(10) == ord('q'):
        break

f.release()
cv.destroyAllWindows()