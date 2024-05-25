from pytube import YouTube
from pydub import AudioSegment
import os

def download_audio_as_mp3(url, output_path, proc):
    try:
        # Create a YouTube object
        yt = YouTube(url)
        
        # Get the first audio-only stream
        audio_stream = yt.streams.filter(only_audio=True).first()
        
        # Download the audio file
        audio_file = audio_stream.download(output_path=output_path)
        
        # Define the MP3 file path
        base, ext = os.path.splitext(audio_file)
        mp3_file = base + '.mp3'

        # For output filename
        remove_path = f"{base.split('/')[8]}"
        audio_filename = remove_path + '.mp3'
        
        # Convert the downloaded file to MP3 using pydub
        AudioSegment.from_file(audio_file).export(mp3_file, format='mp3')
        
        # Optionally, remove the original audio file
        os.remove(audio_file)

        print(f"Downloaded: {audio_filename}")
        print(f">>> End Process Number: {proc} <<<\n")
    except Exception as e:
        print(f'An error occurred: {e}')

if __name__ == '__main__':
    output_path = 'storage/shared'  # Replace with your desired download path
    # Open the file and read line by line
    with open('music.txt', 'r') as file:
        for proc, line in enumerate(file, start=0):
            line = line.strip()
            print(f">>> Start Process Number: {proc} <<<")
            print(f"Downloading: URL[{line}]")
            download_audio_as_mp3(line, output_path, proc=proc)
