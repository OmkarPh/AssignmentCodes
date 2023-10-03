import java.util.*;
import java.util.stream.*;

public class exp5_4{
    
    static class Track{
        public final String name;
        public final int rating;

        public Track(String name, int rating){
            this.name = name;
            this.rating = rating;
        }

        public String toString(){
            return this.name + " (" + this.rating + ") "; 
        }
    }

    static class Album{
        public final String name;
        private final List<Track> tracks;
        private int yearOfRelease;

        public int getYear(){
            return yearOfRelease;
        }
        public List<Track> getTracks(){
            return tracks;
        }

        public int maxRating(){
            Track maxTrack = tracks.stream().reduce(new Track("temp",0), (maxTrackYet, currTrack) -> {
                if(maxTrackYet.rating < currTrack.rating)
                    return currTrack;
                return maxTrackYet;
            });
            return maxTrack.rating;
        }

        public Album(String name, List<Track> trackList, int yearOfRelease){
            this.name = name;
            this.yearOfRelease = yearOfRelease;
            this.tracks = trackList;
        }

        public String toString(){
            return this.name+" ("+this.yearOfRelease+") ";
        }
    }

    static List<String>  sortAlbumsByYear(List<Album> albums){
        Stream albumStream = albums.stream();
        Object sorted[] = albumStream.sorted(Comparator.comparingInt(Album::getYear)).toArray();

        List<String> sortedList = new ArrayList<>();
        for(Object obj : sorted)
            sortedList.add(String.valueOf(obj));

        return sortedList;
    }

    static public List<String> filterGoodAlbums(List<Album> albums){
        List<String> goodAlbums = new ArrayList<>();
        albums.stream().forEach(album -> {
            if(album.maxRating() >4)
                goodAlbums.add(album.toString());
        });
         return goodAlbums;
    }



    public  static void main(String[] args) {

        System.out.println();

        // Preparing albums and tracks
        String[] travelNames = {"Ve maahi", "Duniya", "Bolna", "Kabira", "Vaaste"};
        int[] travelRatings= {5,6,4,8,5};
        List<Track> travelSongs = new  ArrayList<>();
        for(int i=0; i<travelNames.length; i++)
            travelSongs.add(new Track(travelNames[i], travelRatings[i]));
        Album travelAlbum = new Album("Travel",travelSongs, 2009);

        String[] rapNames = {"Mirchi", "ChalBombay", "Kohinoor"};
        int[] rapRatings = {1, 3,2};
        List<Track> rapSongs = new  ArrayList<>();
            for(int i=0; i<rapNames.length; i++)
                rapSongs.add(new Track(rapNames[i], rapRatings[i]));
        Album rapAlbum = new Album("Rap",rapSongs, 2006);
        
        String[] hipHopNames = {"Ve maahi", "Duniya", "Bolna", "Kabira", "Vaaste"};
        int[] hiphopRatings = {5,9,9,4,7};
        List<Track> hipHopSongs = new  ArrayList<>();
                for(int i=0; i<hipHopNames.length; i++)
                hipHopSongs.add(new Track(hipHopNames[i], hiphopRatings[i]));
        Album hipHopAlbum = new Album("Hip hop",hipHopSongs, 2017);
        
        String[] jazzNames = {"Sham", "Masakali","Lovely"};
        int[] jazzRatings = {3,1,2};
        List<Track> jazzSongs = new  ArrayList<>();
        for(int i=0; i<jazzNames.length; i++)
            jazzSongs.add(new Track(jazzNames[i], jazzRatings[i]));
        Album jazzAlbum = new Album("Jazz",jazzSongs, 1995);

        List<String> sortedAlbums =  sortAlbumsByYear(Arrays.asList(travelAlbum, jazzAlbum, hipHopAlbum, rapAlbum));
        System.out.println("Sorted list of albums by their year of release: \n"+sortedAlbums+"\n");

        List<String> goodAlbums =  filterGoodAlbums(Arrays.asList(travelAlbum, jazzAlbum, hipHopAlbum, rapAlbum));
        System.out.println("Sorted list of Good albums(rating>4) by their year of release: \n"+goodAlbums);

    }
}