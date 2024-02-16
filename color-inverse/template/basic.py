# new template insertion
import cv2
import time

class VideoProcessor:
    def __init__(self, video_path, fps):
        self.video_path = video_path
        self.fps = fps

    def process_video(self):
        cap = cv2.VideoCapture(self.video_path)
        if not cap.isOpened():
            print("Error: Failed to open video file.")
            return

        frame_count = 0
        start_time = time.time()

        while cap.isOpened():
            ret, frame = cap.read()
            if not ret:
                break

            # Process frame here (e.g., convert to grayscale, apply filters, etc.)
            # Example:
            # gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
            # processed_frame = cv2.Canny(gray_frame, 100, 200)

            # Display or save the processed frame
            cv2.imshow('Processed Frame', frame)
            cv2.waitKey(30)  # Adjust delay between frames if needed

            frame_count += 1

        cap.release()
        cv2.destroyAllWindows()

        end_time = time.time()
        duration = end_time - start_time
        print(f"Total processing time: {duration:.2f} seconds")
        print(f"Processed {frame_count} frames")

def kernel_as_multithreading_enaplied_as_decentralized():
    # Initialize VideoProcessor with video file path and desired FPS
    video_processor = VideoProcessor("input_video.mp4", 30.0)

    # Process video
    video_processor.process_video()

if __name__ == "__main__":
    kernel_as_multithreading_enaplied_as_decentralized()
