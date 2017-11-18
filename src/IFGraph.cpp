#include <pyOCCT_Common.hpp>

#include <Interface_GraphContent.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <IFGraph_AllConnected.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFGraph_AllShared.hxx>
#include <Standard_TypeDef.hxx>
#include <IFGraph_Articulations.hxx>
#include <IFGraph_Compare.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFGraph_ConnectedComponants.hxx>
#include <IFGraph_Cumulate.hxx>
#include <IFGraph_StrongComponants.hxx>
#include <IFGraph_Cycles.hxx>
#include <IFGraph_ExternalSources.hxx>
#include <IFGraph_SCRoots.hxx>

PYBIND11_MODULE(IFGraph, mod) {

	// IMPORT
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_AllConnected.hxx
	py::class_<IFGraph_AllConnected, std::unique_ptr<IFGraph_AllConnected, Deleter<IFGraph_AllConnected>>, Interface_GraphContent> cls_IFGraph_AllConnected(mod, "IFGraph_AllConnected", "this class gives content of the CONNECTED COMPONANT(S) which include specific Entity(ies)");
	cls_IFGraph_AllConnected.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
	cls_IFGraph_AllConnected.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));
	cls_IFGraph_AllConnected.def("GetFromEntity", (void (IFGraph_AllConnected::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_AllConnected::GetFromEntity, "adds an entity and its Connected ones to the list (allows to cumulate all Entities Connected by some ones) Note that if 'ent' is in the already computed list,, no entity will be added, but if 'ent' is not already in the list, a new Connected Componant will be cumulated", py::arg("ent"));
	cls_IFGraph_AllConnected.def("ResetData", (void (IFGraph_AllConnected::*)()) &IFGraph_AllConnected::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_AllConnected.def("Evaluate", (void (IFGraph_AllConnected::*)()) &IFGraph_AllConnected::Evaluate, "does the specific evaluation (Connected entities atall levels)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_AllShared.hxx
	py::class_<IFGraph_AllShared, std::unique_ptr<IFGraph_AllShared, Deleter<IFGraph_AllShared>>, Interface_GraphContent> cls_IFGraph_AllShared(mod, "IFGraph_AllShared", "this class determines all Entities shared by some specific ones, at any level (those which will be lead in a Transfer for instance)");
	cls_IFGraph_AllShared.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
	cls_IFGraph_AllShared.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));
	cls_IFGraph_AllShared.def("GetFromEntity", (void (IFGraph_AllShared::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_AllShared::GetFromEntity, "adds an entity and its shared ones to the list (allows to cumulate all Entities shared by some ones)", py::arg("ent"));
	cls_IFGraph_AllShared.def("GetFromIter", (void (IFGraph_AllShared::*)(const Interface_EntityIterator &)) &IFGraph_AllShared::GetFromIter, "Adds Entities from an EntityIterator and all their shared ones at any level", py::arg("iter"));
	cls_IFGraph_AllShared.def("ResetData", (void (IFGraph_AllShared::*)()) &IFGraph_AllShared::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_AllShared.def("Evaluate", (void (IFGraph_AllShared::*)()) &IFGraph_AllShared::Evaluate, "does the specific evaluation (shared entities atall levels)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_Articulations.hxx
	py::class_<IFGraph_Articulations, std::unique_ptr<IFGraph_Articulations, Deleter<IFGraph_Articulations>>, Interface_GraphContent> cls_IFGraph_Articulations(mod, "IFGraph_Articulations", "this class gives entities which are Articulation points in a whole Model or in a sub-part An Articulation Point divides the graph in two (or more) disconnected sub-graphs Identifying Articulation Points allows improving efficiency of spliting a set of Entities into sub-sets");
	cls_IFGraph_Articulations.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_Articulations.def("GetFromEntity", (void (IFGraph_Articulations::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_Articulations::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
	cls_IFGraph_Articulations.def("GetFromIter", (void (IFGraph_Articulations::*)(const Interface_EntityIterator &)) &IFGraph_Articulations::GetFromIter, "adds a list of entities (as an iterator)", py::arg("iter"));
	cls_IFGraph_Articulations.def("ResetData", (void (IFGraph_Articulations::*)()) &IFGraph_Articulations::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_Articulations.def("Evaluate", (void (IFGraph_Articulations::*)()) &IFGraph_Articulations::Evaluate, "Evaluates the list of Articulation points");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_Compare.hxx
	py::class_<IFGraph_Compare, std::unique_ptr<IFGraph_Compare, Deleter<IFGraph_Compare>>, Interface_GraphContent> cls_IFGraph_Compare(mod, "IFGraph_Compare", "this class evaluates effect of two compared sub-parts : cumulation (union), common part (intersection-overlapping) part specific to first sub-part or to the second one Results are kept in a Graph, several question can be set Basic Iteration gives Cumulation (union)");
	cls_IFGraph_Compare.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
	cls_IFGraph_Compare.def("GetFromEntity", (void (IFGraph_Compare::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFGraph_Compare::GetFromEntity, "adds an entity and its shared ones to the list : first True means adds to the first sub-list, else to the 2nd", py::arg("ent"), py::arg("first"));
	cls_IFGraph_Compare.def("GetFromIter", (void (IFGraph_Compare::*)(const Interface_EntityIterator &, const Standard_Boolean)) &IFGraph_Compare::GetFromIter, "adds a list of entities (as an iterator) as such, that is, their shared entities are not considered (use AllShared to have them) first True means adds to the first sub-list, else to the 2nd", py::arg("iter"), py::arg("first"));
	cls_IFGraph_Compare.def("Merge", (void (IFGraph_Compare::*)()) &IFGraph_Compare::Merge, "merges the second list into the first one, hence the second list is empty");
	cls_IFGraph_Compare.def("RemoveSecond", (void (IFGraph_Compare::*)()) &IFGraph_Compare::RemoveSecond, "Removes the contents of second list");
	cls_IFGraph_Compare.def("KeepCommon", (void (IFGraph_Compare::*)()) &IFGraph_Compare::KeepCommon, "Keeps only Common part, sets it as First list and clears second list");
	cls_IFGraph_Compare.def("ResetData", (void (IFGraph_Compare::*)()) &IFGraph_Compare::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_Compare.def("Evaluate", (void (IFGraph_Compare::*)()) &IFGraph_Compare::Evaluate, "Recomputes result of comparing to sub-parts");
	cls_IFGraph_Compare.def("Common", (Interface_EntityIterator (IFGraph_Compare::*)() const ) &IFGraph_Compare::Common, "returns entities common to the both parts");
	cls_IFGraph_Compare.def("FirstOnly", (Interface_EntityIterator (IFGraph_Compare::*)() const ) &IFGraph_Compare::FirstOnly, "returns entities which are exclusively in the first list");
	cls_IFGraph_Compare.def("SecondOnly", (Interface_EntityIterator (IFGraph_Compare::*)() const ) &IFGraph_Compare::SecondOnly, "returns entities which are exclusively in the second part");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_SubPartsIterator.hxx
	py::class_<IFGraph_SubPartsIterator, std::unique_ptr<IFGraph_SubPartsIterator, Deleter<IFGraph_SubPartsIterator>>> cls_IFGraph_SubPartsIterator(mod, "IFGraph_SubPartsIterator", "defines general form for graph classes of which result is not a single iteration on Entities, but a nested one : External iteration works on sub-parts, identified by each class (according to its algorithm) Internal Iteration concerns Entities of a sub-part Sub-Parts are assumed to be disjoined; if they are not, the first one has priority");
	cls_IFGraph_SubPartsIterator.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_SubPartsIterator.def(py::init([] (IFGraph_SubPartsIterator &other) {return new IFGraph_SubPartsIterator(other);}), "Copy constructor", py::arg("other"));
	cls_IFGraph_SubPartsIterator.def("GetParts", (void (IFGraph_SubPartsIterator::*)(IFGraph_SubPartsIterator &)) &IFGraph_SubPartsIterator::GetParts, "Gets Parts from another SubPartsIterator (in addition to the ones already recorded) Error if both SubPartsIterators are not based on the same Model", py::arg("other"));
	cls_IFGraph_SubPartsIterator.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::Model, "Returns the Model with which this Iterator was created");
	cls_IFGraph_SubPartsIterator.def("AddPart", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::AddPart, "Adds an empty part and sets it to receive entities");
	cls_IFGraph_SubPartsIterator.def("NbParts", (Standard_Integer (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::NbParts, "Returns count of registered parts");
	cls_IFGraph_SubPartsIterator.def("PartNum", (Standard_Integer (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::PartNum, "Returns numero of part which currently receives entities (0 at load time)");
	cls_IFGraph_SubPartsIterator.def("SetLoad", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::SetLoad, "Sets SubPartIterator to get Entities (by GetFromEntity & GetFromIter) into load status, to be analysed later");
	cls_IFGraph_SubPartsIterator.def("SetPartNum", (void (IFGraph_SubPartsIterator::*)(const Standard_Integer)) &IFGraph_SubPartsIterator::SetPartNum, "Sets numero of receiving part to a new value Error if not in range (1-NbParts)", py::arg("num"));
	cls_IFGraph_SubPartsIterator.def("GetFromEntity", (void (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFGraph_SubPartsIterator::GetFromEntity, "Adds an Entity : into load status if in Load mode, to the current part if there is one. If shared is True, adds also its shared ones (shared at all levels)", py::arg("ent"), py::arg("shared"));
	cls_IFGraph_SubPartsIterator.def("GetFromIter", (void (IFGraph_SubPartsIterator::*)(const Interface_EntityIterator &)) &IFGraph_SubPartsIterator::GetFromIter, "Adds a list of Entities (into Load mode or to a Part), given as an Iterator", py::arg("iter"));
	cls_IFGraph_SubPartsIterator.def("Reset", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Reset, "Erases data (parts, entities) : 'me' becomes empty and in load status");
	cls_IFGraph_SubPartsIterator.def("Evaluate", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Evaluate, "Called by Clear, this method allows evaluation just before iteration; its default is doing nothing, it is designed to be redefined");
	cls_IFGraph_SubPartsIterator.def("Loaded", (Interface_GraphContent (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::Loaded, "Returns entities which where loaded (not set into a sub-part)");
	cls_IFGraph_SubPartsIterator.def("LoadedGraph", (Interface_Graph (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::LoadedGraph, "Same as above, but under the form of a Graph");
	cls_IFGraph_SubPartsIterator.def("IsLoaded", (Standard_Boolean (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const ) &IFGraph_SubPartsIterator::IsLoaded, "Returns True if an Entity is loaded (either set into a sub-part or not)", py::arg("ent"));
	cls_IFGraph_SubPartsIterator.def("IsInPart", (Standard_Boolean (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const ) &IFGraph_SubPartsIterator::IsInPart, "Returns True if an Entity is Present in a sub-part", py::arg("ent"));
	cls_IFGraph_SubPartsIterator.def("EntityPartNum", (Standard_Integer (IFGraph_SubPartsIterator::*)(const opencascade::handle<Standard_Transient> &) const ) &IFGraph_SubPartsIterator::EntityPartNum, "Returns number of the sub-part in which an Entity has been set if it is not in a sub-part (or not loaded at all), Returns 0", py::arg("ent"));
	cls_IFGraph_SubPartsIterator.def("Start", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Start, "Sets iteration to its beginning; calls Evaluate");
	cls_IFGraph_SubPartsIterator.def("More", (Standard_Boolean (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::More, "Returns True if there are more sub-parts to iterate on Note : an empty sub-part is not taken in account by Iteration");
	cls_IFGraph_SubPartsIterator.def("Next", (void (IFGraph_SubPartsIterator::*)()) &IFGraph_SubPartsIterator::Next, "Sets iteration to the next sub-part if there is not, IsSingle-Entities will raises an exception");
	cls_IFGraph_SubPartsIterator.def("IsSingle", (Standard_Boolean (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::IsSingle, "Returns True if current sub-part is single (has only one Entity) Error if there is no sub-part to iterate now");
	cls_IFGraph_SubPartsIterator.def("FirstEntity", (opencascade::handle<Standard_Transient> (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::FirstEntity, "Returns the first entity of current sub-part, that is for a Single one, the only one it contains Error : same as above (end of iteration)");
	cls_IFGraph_SubPartsIterator.def("Entities", (Interface_EntityIterator (IFGraph_SubPartsIterator::*)() const ) &IFGraph_SubPartsIterator::Entities, "Returns current sub-part, not as a 'Value', but as an Iterator on Entities it contains Error : same as above (end of iteration)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_ConnectedComponants.hxx
	py::class_<IFGraph_ConnectedComponants, std::unique_ptr<IFGraph_ConnectedComponants, Deleter<IFGraph_ConnectedComponants>>, IFGraph_SubPartsIterator> cls_IFGraph_ConnectedComponants(mod, "IFGraph_ConnectedComponants", "determines Connected Componants in a Graph. They define disjoined sets of Entities");
	cls_IFGraph_ConnectedComponants.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_ConnectedComponants.def("Evaluate", (void (IFGraph_ConnectedComponants::*)()) &IFGraph_ConnectedComponants::Evaluate, "does the computation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_Cumulate.hxx
	py::class_<IFGraph_Cumulate, std::unique_ptr<IFGraph_Cumulate, Deleter<IFGraph_Cumulate>>, Interface_GraphContent> cls_IFGraph_Cumulate(mod, "IFGraph_Cumulate", "this class evaluates effect of cumulated sub-parts : overlapping, forgotten entities Results are kept in a Graph, several question can be set Basic Iteration gives entities which are part of Cumulation");
	cls_IFGraph_Cumulate.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
	cls_IFGraph_Cumulate.def("GetFromEntity", (void (IFGraph_Cumulate::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_Cumulate::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
	cls_IFGraph_Cumulate.def("GetFromIter", (void (IFGraph_Cumulate::*)(const Interface_EntityIterator &)) &IFGraph_Cumulate::GetFromIter, "adds a list of entities (as an iterator) as such, that is, without their shared entities (use AllShared to have them)", py::arg("iter"));
	cls_IFGraph_Cumulate.def("ResetData", (void (IFGraph_Cumulate::*)()) &IFGraph_Cumulate::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_Cumulate.def("Evaluate", (void (IFGraph_Cumulate::*)()) &IFGraph_Cumulate::Evaluate, "Evaluates the result of cumulation");
	cls_IFGraph_Cumulate.def("Overlapped", (Interface_EntityIterator (IFGraph_Cumulate::*)() const ) &IFGraph_Cumulate::Overlapped, "returns entities which are taken several times");
	cls_IFGraph_Cumulate.def("Forgotten", (Interface_EntityIterator (IFGraph_Cumulate::*)() const ) &IFGraph_Cumulate::Forgotten, "returns entities which are not taken");
	cls_IFGraph_Cumulate.def("PerCount", [](IFGraph_Cumulate &self) -> Interface_EntityIterator { return self.PerCount(); });
	cls_IFGraph_Cumulate.def("PerCount", (Interface_EntityIterator (IFGraph_Cumulate::*)(const Standard_Integer) const ) &IFGraph_Cumulate::PerCount, "Returns entities taken a given count of times (0 : same as Forgotten, 1 : same as no Overlap : default)", py::arg("count"));
	cls_IFGraph_Cumulate.def("NbTimes", (Standard_Integer (IFGraph_Cumulate::*)(const opencascade::handle<Standard_Transient> &) const ) &IFGraph_Cumulate::NbTimes, "returns number of times an Entity has been counted (0 means forgotten, more than 1 means overlap, 1 is normal)", py::arg("ent"));
	cls_IFGraph_Cumulate.def("HighestNbTimes", (Standard_Integer (IFGraph_Cumulate::*)() const ) &IFGraph_Cumulate::HighestNbTimes, "Returns the highest number of times recorded for every Entity (0 means empty, 1 means no overlap)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_StrongComponants.hxx
	py::class_<IFGraph_StrongComponants, std::unique_ptr<IFGraph_StrongComponants, Deleter<IFGraph_StrongComponants>>, IFGraph_SubPartsIterator> cls_IFGraph_StrongComponants(mod, "IFGraph_StrongComponants", "determines strong componants of a graph, that is isolated entities (single componants) or loops");
	cls_IFGraph_StrongComponants.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_StrongComponants.def("Evaluate", (void (IFGraph_StrongComponants::*)()) &IFGraph_StrongComponants::Evaluate, "does the computation");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_Cycles.hxx
	py::class_<IFGraph_Cycles, std::unique_ptr<IFGraph_Cycles, Deleter<IFGraph_Cycles>>, IFGraph_SubPartsIterator> cls_IFGraph_Cycles(mod, "IFGraph_Cycles", "determines strong componants in a graph which are Cycles");
	cls_IFGraph_Cycles.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_Cycles.def(py::init<IFGraph_StrongComponants &>(), py::arg("subparts"));
	cls_IFGraph_Cycles.def("Evaluate", (void (IFGraph_Cycles::*)()) &IFGraph_Cycles::Evaluate, "does the computation. Cycles are StrongComponants which are not Single");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_ExternalSources.hxx
	py::class_<IFGraph_ExternalSources, std::unique_ptr<IFGraph_ExternalSources, Deleter<IFGraph_ExternalSources>>, Interface_GraphContent> cls_IFGraph_ExternalSources(mod, "IFGraph_ExternalSources", "this class gives entities which are Source of entities of a sub-part, but are not contained by this sub-part");
	cls_IFGraph_ExternalSources.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
	cls_IFGraph_ExternalSources.def("GetFromEntity", (void (IFGraph_ExternalSources::*)(const opencascade::handle<Standard_Transient> &)) &IFGraph_ExternalSources::GetFromEntity, "adds an entity and its shared ones to the list", py::arg("ent"));
	cls_IFGraph_ExternalSources.def("GetFromIter", (void (IFGraph_ExternalSources::*)(const Interface_EntityIterator &)) &IFGraph_ExternalSources::GetFromIter, "adds a list of entities (as an iterator) with shared ones", py::arg("iter"));
	cls_IFGraph_ExternalSources.def("ResetData", (void (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::ResetData, "Allows to restart on a new data set");
	cls_IFGraph_ExternalSources.def("Evaluate", (void (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::Evaluate, "Evaluates external sources of a set of entities");
	cls_IFGraph_ExternalSources.def("IsEmpty", (Standard_Boolean (IFGraph_ExternalSources::*)()) &IFGraph_ExternalSources::IsEmpty, "Returns True if no External Source are found It means that we have a 'root' set (performs an Evaluation as necessary)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IFGraph_SCRoots.hxx
	py::class_<IFGraph_SCRoots, std::unique_ptr<IFGraph_SCRoots, Deleter<IFGraph_SCRoots>>, IFGraph_StrongComponants> cls_IFGraph_SCRoots(mod, "IFGraph_SCRoots", "determines strong componants in a graph which are Roots");
	cls_IFGraph_SCRoots.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("whole"));
	cls_IFGraph_SCRoots.def(py::init<IFGraph_StrongComponants &>(), py::arg("subparts"));
	cls_IFGraph_SCRoots.def("Evaluate", (void (IFGraph_SCRoots::*)()) &IFGraph_SCRoots::Evaluate, "does the computation");


}
