#include "GlobalHeader.h"
#include "Program.h"
#include "Scene.h"
#include "ReadFile.h"

string tmpTest = "Scene1;9;Lorem ipsum dolor sit amet, consectetur adipiscing elit.Aenean orci felis, aliquet ut condimentum eu, dapibus eget eros.Etiam aliquam, risus vel tempor auctor, quam leo sagittis purus, ac aliquet diam arcu sit amet nibh.Cras lacinia lobortis semper.Quisque rhoncus ante tincidunt ante venenatis, ut viverra libero molestie.Interdum et malesuada fames ac ante ipsum primis in faucibus.Quisque ut sapien et lorem pretium dictum in non nunc.Donec sollicitudin lacus vel aliquet aliquam.Aenean sit amet faucibus est.Duis in vehicula massa, ac tincidunt orci.\n [[123]] [[]] [[]] Mauris vel odio non ligula egestas tempus.Sed porta arcu vel placerat iaculis.Proin sollicitudin lacus lectus, vitae ornare augue ultrices at.Morbi interdum accumsan odio, sit amet iaculis velit auctor ac.Nullam tellus nulla, dignissim ut mi nec, rhoncus mattis arcu.Mauris in rhoncus nisl.Proin rhoncus gravida sapien, eget convallis quam euismod non.\n [[20]] [[gun, ammunition]] [[]] Nam at tincidunt ligula, sit amet ullamcorper erat.Donec mollis ullamcorper vehicula.Donec nec nunc augue.Nam nec dapibus elit.Integer malesuada, mi vitae feugiat luctus, quam magna congue magna, nec bibendum mi mauris eget est.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Fusce non sagittis purus.Mauris ut luctus mauris.Aenean porttitor nunc dolor, et pellentesque mauris pulvinar sit amet.Vivamus eu risus non magna aliquam bibendum.Aenean aliquam maximus libero, non vehicula magna ornare et.Nam non est vulputate, elementum eros nec, gravida leo.\n [[]] [[food]] [[-food, +lol]] Integer non bibendum nibh.Nam erat velit, semper nec euismod tempus, luctus sollicitudin mauris.Vestibulum cursus, turpis sit amet gravida dapibus, tortor velit porttitor nibh, congue fringilla dolor purus eu eros.Sed scelerisque, quam quis ornare facilisis, velit dolor dictum massa, ac tincidunt lectus dolor vitae tortor.Suspendisse placerat lorem arcu, vitae porttitor augue tristique sed.Donec luctus massa vitae molestie condimentum.Phasellus dapibus sagittis urna, sit amet convallis nisi facilisis ut.Suspendisse ac pharetra enim.Fusce feugiat volutpat accumsan.Ut ac rutrum urna.Aenean eu ex vehicula risus commodo efficitur at in lacus.Proin lobortis, orci nec rhoncus mattis, quam dui condimentum dui, a auctor leo turpis eu leo.Etiam facilisis odio augue, at efficitur lacus blandit ultrices.Aliquam velit ipsum, pulvinar in iaculis vel, interdum at est.\n [[5]] [[]] [[]] Sed id aliquam magna.Donec cursus, augue vitae rutrum aliquet, ipsum tellus porttitor magna, ut porttitor lacus sem vel turpis.Praesent ultricies tortor sit amet lorem porttitor, vel fermentum ipsum ullamcorper.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Ut egestas mollis mi sit amet bibendum.Vestibulum lacinia sollicitudin enim, dapibus ullamcorper neque maximus vitae.Quisque ac quam hendrerit, consectetur massa at, fermentum tellus.Praesent vitae iaculis neque.Nunc mollis vestibulum dui nec tristique.Phasellus sagittis vehicula sapien, ut feugiat dui commodo ut.Suspendisse vitae ipsum at quam elementum accumsan.In vitae purus pharetra, vestibulum ligula at, dapibus purus.Suspendisse at erat a lectus mollis ullamcorper sed sit amet erat.Curabitur nunc leo, consequat consectetur ultricies ut, mattis et tortor.Aenean volutpat nunc mi, vitae molestie mauris ultrices vitae.\n [[]] [[thirsty]] [[+water]] ;0;Answering calmly to the Colonel;;;Scene 2;0;Answering strongly to the Colonel;;;Scene 3;;;;;";

string dontCloseCmdWindows;

int main(int argc, char* argv[]) {
	ReadFile::Start(tmpTest);

	cin >> dontCloseCmdWindows;
}