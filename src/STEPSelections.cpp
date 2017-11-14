#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <STEPSelections_HSequenceOfAssemblyLink.hxx>
#include <Standard_Type.hxx>
#include <STEPSelections_AssemblyComponent.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <STEPSelections_AssemblyLink.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <STEPSelections_SequenceOfAssemblyLink.hxx>
#include <STEPSelections_SequenceOfAssemblyComponent.hxx>
#include <Interface_Graph.hxx>
#include <Standard_OStream.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <STEPSelections_AssemblyExplorer.hxx>
#include <STEPSelections_Counter.hxx>
#include <IFSelect_SelectExplore.hxx>
#include <Interface_EntityIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <STEPSelections_SelectAssembly.hxx>
#include <StepSelect_StepType.hxx>
#include <Interface_InterfaceModel.hxx>
#include <STEPSelections_SelectDerived.hxx>
#include <STEPSelections_SelectFaces.hxx>
#include <XSControl_SelectForTransfer.hxx>
#include <XSControl_TransferReader.hxx>
#include <STEPSelections_SelectForTransfer.hxx>
#include <STEPSelections_SelectGSCurves.hxx>
#include <STEPSelections_SelectInstances.hxx>

PYBIND11_MODULE(STEPSelections, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Interface");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.IFSelect");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepSelect");
	py::module::import("OCCT.XSControl");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_AssemblyComponent.hxx
	py::class_<STEPSelections_AssemblyComponent, opencascade::handle<STEPSelections_AssemblyComponent>, Standard_Transient> cls_STEPSelections_AssemblyComponent(mod, "STEPSelections_AssemblyComponent", "None");
	cls_STEPSelections_AssemblyComponent.def(py::init<>());
	cls_STEPSelections_AssemblyComponent.def(py::init<const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> &>(), py::arg("sdr"), py::arg("list"));
	cls_STEPSelections_AssemblyComponent.def("GetSDR", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPSelections_AssemblyComponent::*)() const ) &STEPSelections_AssemblyComponent::GetSDR, "None");
	cls_STEPSelections_AssemblyComponent.def("GetList", (opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> (STEPSelections_AssemblyComponent::*)() const ) &STEPSelections_AssemblyComponent::GetList, "None");
	cls_STEPSelections_AssemblyComponent.def("SetSDR", (void (STEPSelections_AssemblyComponent::*)(const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &)) &STEPSelections_AssemblyComponent::SetSDR, "None", py::arg("sdr"));
	cls_STEPSelections_AssemblyComponent.def("SetList", (void (STEPSelections_AssemblyComponent::*)(const opencascade::handle<STEPSelections_HSequenceOfAssemblyLink> &)) &STEPSelections_AssemblyComponent::SetList, "None", py::arg("list"));
	cls_STEPSelections_AssemblyComponent.def_static("get_type_name_", (const char * (*)()) &STEPSelections_AssemblyComponent::get_type_name, "None");
	cls_STEPSelections_AssemblyComponent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_AssemblyComponent::get_type_descriptor, "None");
	cls_STEPSelections_AssemblyComponent.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_AssemblyComponent::*)() const ) &STEPSelections_AssemblyComponent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_AssemblyLink.hxx
	py::class_<STEPSelections_AssemblyLink, opencascade::handle<STEPSelections_AssemblyLink>, Standard_Transient> cls_STEPSelections_AssemblyLink(mod, "STEPSelections_AssemblyLink", "None");
	cls_STEPSelections_AssemblyLink.def(py::init<>());
	cls_STEPSelections_AssemblyLink.def(py::init<const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<STEPSelections_AssemblyComponent> &>(), py::arg("nauo"), py::arg("item"), py::arg("part"));
	cls_STEPSelections_AssemblyLink.def("GetNAUO", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (STEPSelections_AssemblyLink::*)() const ) &STEPSelections_AssemblyLink::GetNAUO, "None");
	cls_STEPSelections_AssemblyLink.def("GetItem", (opencascade::handle<Standard_Transient> (STEPSelections_AssemblyLink::*)() const ) &STEPSelections_AssemblyLink::GetItem, "None");
	cls_STEPSelections_AssemblyLink.def("GetComponent", (opencascade::handle<STEPSelections_AssemblyComponent> (STEPSelections_AssemblyLink::*)() const ) &STEPSelections_AssemblyLink::GetComponent, "None");
	cls_STEPSelections_AssemblyLink.def("SetNAUO", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &STEPSelections_AssemblyLink::SetNAUO, "None", py::arg("nauo"));
	cls_STEPSelections_AssemblyLink.def("SetItem", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<Standard_Transient> &)) &STEPSelections_AssemblyLink::SetItem, "None", py::arg("item"));
	cls_STEPSelections_AssemblyLink.def("SetComponent", (void (STEPSelections_AssemblyLink::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_AssemblyLink::SetComponent, "None", py::arg("part"));
	cls_STEPSelections_AssemblyLink.def_static("get_type_name_", (const char * (*)()) &STEPSelections_AssemblyLink::get_type_name, "None");
	cls_STEPSelections_AssemblyLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_AssemblyLink::get_type_descriptor, "None");
	cls_STEPSelections_AssemblyLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_AssemblyLink::*)() const ) &STEPSelections_AssemblyLink::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<STEPSelections_SequenceOfAssemblyLink, std::unique_ptr<STEPSelections_SequenceOfAssemblyLink, Deleter<STEPSelections_SequenceOfAssemblyLink>>, NCollection_BaseSequence> cls_STEPSelections_SequenceOfAssemblyLink(mod, "STEPSelections_SequenceOfAssemblyLink", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_STEPSelections_SequenceOfAssemblyLink.def(py::init<>());
	cls_STEPSelections_SequenceOfAssemblyLink.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_STEPSelections_SequenceOfAssemblyLink.def(py::init([] (const STEPSelections_SequenceOfAssemblyLink &other) {return new STEPSelections_SequenceOfAssemblyLink(other);}), "Copy constructor", py::arg("other"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("begin", (STEPSelections_SequenceOfAssemblyLink::iterator (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("end", (STEPSelections_SequenceOfAssemblyLink::iterator (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("cbegin", (STEPSelections_SequenceOfAssemblyLink::const_iterator (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("cend", (STEPSelections_SequenceOfAssemblyLink::const_iterator (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Size", (Standard_Integer (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::Size, "Number of items");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Length", (Standard_Integer (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::Length, "Number of items");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Lower", (Standard_Integer (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::Lower, "Method for consistency with other collections.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Upper", (Standard_Integer (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::Upper, "Method for consistency with other collections.");
	cls_STEPSelections_SequenceOfAssemblyLink.def("IsEmpty", (Standard_Boolean (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::IsEmpty, "Empty query");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Reverse", (void (STEPSelections_SequenceOfAssemblyLink::*)()) &STEPSelections_SequenceOfAssemblyLink::Reverse, "Reverse sequence");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Exchange", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, const Standard_Integer)) &STEPSelections_SequenceOfAssemblyLink::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_STEPSelections_SequenceOfAssemblyLink.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_SequenceOfAssemblyLink::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Clear", [](STEPSelections_SequenceOfAssemblyLink &self) -> void { return self.Clear(); });
	cls_STEPSelections_SequenceOfAssemblyLink.def("Clear", (void (STEPSelections_SequenceOfAssemblyLink::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_SequenceOfAssemblyLink::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Assign", (STEPSelections_SequenceOfAssemblyLink & (STEPSelections_SequenceOfAssemblyLink::*)(const STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("assign", (STEPSelections_SequenceOfAssemblyLink & (STEPSelections_SequenceOfAssemblyLink::*)(const STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Remove", (void (STEPSelections_SequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink::Iterator &)) &STEPSelections_SequenceOfAssemblyLink::Remove, "Remove one item", py::arg("thePosition"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Remove", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyLink::Remove, "Remove one item", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Remove", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, const Standard_Integer)) &STEPSelections_SequenceOfAssemblyLink::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Append", (void (STEPSelections_SequenceOfAssemblyLink::*)(const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::Append, "Append one item", py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Append", (void (STEPSelections_SequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Prepend", (void (STEPSelections_SequenceOfAssemblyLink::*)(const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::Prepend, "Prepend one item", py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Prepend", (void (STEPSelections_SequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("InsertBefore", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("InsertBefore", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink::Iterator &, const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("Split", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_SequenceOfAssemblyLink::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("First", (const opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::First, "First item access");
	cls_STEPSelections_SequenceOfAssemblyLink.def("ChangeFirst", (opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)()) &STEPSelections_SequenceOfAssemblyLink::ChangeFirst, "First item access");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Last", (const opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)() const ) &STEPSelections_SequenceOfAssemblyLink::Last, "Last item access");
	cls_STEPSelections_SequenceOfAssemblyLink.def("ChangeLast", (opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)()) &STEPSelections_SequenceOfAssemblyLink::ChangeLast, "Last item access");
	cls_STEPSelections_SequenceOfAssemblyLink.def("Value", (const opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer) const ) &STEPSelections_SequenceOfAssemblyLink::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("__call__", (const opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer) const ) &STEPSelections_SequenceOfAssemblyLink::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("ChangeValue", (opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyLink::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("__call__", (opencascade::handle<STEPSelections_AssemblyLink> & (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyLink::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("SetValue", (void (STEPSelections_SequenceOfAssemblyLink::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyLink> &)) &STEPSelections_SequenceOfAssemblyLink::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyLink.def("__iter__", [](const STEPSelections_SequenceOfAssemblyLink &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_AssemblyExplorer.hxx
	py::class_<STEPSelections_AssemblyExplorer, std::unique_ptr<STEPSelections_AssemblyExplorer, Deleter<STEPSelections_AssemblyExplorer>>> cls_STEPSelections_AssemblyExplorer(mod, "STEPSelections_AssemblyExplorer", "None");
	cls_STEPSelections_AssemblyExplorer.def(py::init<const Interface_Graph &>(), py::arg("G"));
	cls_STEPSelections_AssemblyExplorer.def("Init", (void (STEPSelections_AssemblyExplorer::*)(const Interface_Graph &)) &STEPSelections_AssemblyExplorer::Init, "None", py::arg("G"));
	// FIXME cls_STEPSelections_AssemblyExplorer.def("Dump", (void (STEPSelections_AssemblyExplorer::*)(Standard_OStream &) const ) &STEPSelections_AssemblyExplorer::Dump, "None", py::arg("os"));
	cls_STEPSelections_AssemblyExplorer.def("FindSDRWithProduct", (opencascade::handle<StepShape_ShapeDefinitionRepresentation> (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<StepBasic_ProductDefinition> &) const ) &STEPSelections_AssemblyExplorer::FindSDRWithProduct, "None", py::arg("product"));
	cls_STEPSelections_AssemblyExplorer.def("FillListWithGraph", (void (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_AssemblyExplorer::FillListWithGraph, "None", py::arg("cmp"));
	cls_STEPSelections_AssemblyExplorer.def("FindItemWithNAUO", (opencascade::handle<Standard_Transient> (STEPSelections_AssemblyExplorer::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &) const ) &STEPSelections_AssemblyExplorer::FindItemWithNAUO, "None", py::arg("nauo"));
	cls_STEPSelections_AssemblyExplorer.def("NbAssemblies", (Standard_Integer (STEPSelections_AssemblyExplorer::*)() const ) &STEPSelections_AssemblyExplorer::NbAssemblies, "Returns the number of root assemblies;");
	cls_STEPSelections_AssemblyExplorer.def("Root", [](STEPSelections_AssemblyExplorer &self) -> opencascade::handle<STEPSelections_AssemblyComponent> { return self.Root(); });
	cls_STEPSelections_AssemblyExplorer.def("Root", (opencascade::handle<STEPSelections_AssemblyComponent> (STEPSelections_AssemblyExplorer::*)(const Standard_Integer) const ) &STEPSelections_AssemblyExplorer::Root, "Returns root of assenbly by its rank;", py::arg("rank"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_Counter.hxx
	py::class_<STEPSelections_Counter, std::unique_ptr<STEPSelections_Counter, Deleter<STEPSelections_Counter>>> cls_STEPSelections_Counter(mod, "STEPSelections_Counter", "None");
	cls_STEPSelections_Counter.def(py::init<>());
	cls_STEPSelections_Counter.def("Count", (void (STEPSelections_Counter::*)(const Interface_Graph &, const opencascade::handle<Standard_Transient> &)) &STEPSelections_Counter::Count, "None", py::arg("graph"), py::arg("start"));
	cls_STEPSelections_Counter.def("Clear", (void (STEPSelections_Counter::*)()) &STEPSelections_Counter::Clear, "None");
	cls_STEPSelections_Counter.def("NbInstancesOfFaces", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbInstancesOfFaces, "None");
	cls_STEPSelections_Counter.def("POP", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::POP, "None");
	cls_STEPSelections_Counter.def("POP2", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::POP2, "None");
	cls_STEPSelections_Counter.def("NbInstancesOfShells", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbInstancesOfShells, "None");
	cls_STEPSelections_Counter.def("NbInstancesOfSolids", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbInstancesOfSolids, "None");
	cls_STEPSelections_Counter.def("NbInstancesOfEdges", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbInstancesOfEdges, "None");
	cls_STEPSelections_Counter.def("NbInstancesOfWires", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbInstancesOfWires, "None");
	cls_STEPSelections_Counter.def("NbSourceFaces", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbSourceFaces, "None");
	cls_STEPSelections_Counter.def("NbSourceShells", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbSourceShells, "None");
	cls_STEPSelections_Counter.def("NbSourceSolids", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbSourceSolids, "None");
	cls_STEPSelections_Counter.def("NbSourceEdges", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbSourceEdges, "None");
	cls_STEPSelections_Counter.def("NbSourceWires", (Standard_Integer (STEPSelections_Counter::*)() const ) &STEPSelections_Counter::NbSourceWires, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectAssembly.hxx
	py::class_<STEPSelections_SelectAssembly, opencascade::handle<STEPSelections_SelectAssembly>, IFSelect_SelectExplore> cls_STEPSelections_SelectAssembly(mod, "STEPSelections_SelectAssembly", "None");
	cls_STEPSelections_SelectAssembly.def(py::init<>());
	cls_STEPSelections_SelectAssembly.def("Explore", (Standard_Boolean (STEPSelections_SelectAssembly::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const ) &STEPSelections_SelectAssembly::Explore, "Explores an entity, to take its faces Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
	cls_STEPSelections_SelectAssembly.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectAssembly::*)() const ) &STEPSelections_SelectAssembly::ExploreLabel, "Returns a text defining the criterium : 'Assembly structures'");
	cls_STEPSelections_SelectAssembly.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectAssembly::get_type_name, "None");
	cls_STEPSelections_SelectAssembly.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectAssembly::get_type_descriptor, "None");
	cls_STEPSelections_SelectAssembly.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectAssembly::*)() const ) &STEPSelections_SelectAssembly::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectDerived.hxx
	py::class_<STEPSelections_SelectDerived, opencascade::handle<STEPSelections_SelectDerived>, StepSelect_StepType> cls_STEPSelections_SelectDerived(mod, "STEPSelections_SelectDerived", "None");
	cls_STEPSelections_SelectDerived.def(py::init<>());
	cls_STEPSelections_SelectDerived.def("Matches", (Standard_Boolean (STEPSelections_SelectDerived::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const ) &STEPSelections_SelectDerived::Matches, "None", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
	cls_STEPSelections_SelectDerived.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectDerived::get_type_name, "None");
	cls_STEPSelections_SelectDerived.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectDerived::get_type_descriptor, "None");
	cls_STEPSelections_SelectDerived.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectDerived::*)() const ) &STEPSelections_SelectDerived::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectFaces.hxx
	py::class_<STEPSelections_SelectFaces, opencascade::handle<STEPSelections_SelectFaces>, IFSelect_SelectExplore> cls_STEPSelections_SelectFaces(mod, "STEPSelections_SelectFaces", "This selection returns 'STEP faces'");
	cls_STEPSelections_SelectFaces.def(py::init<>());
	cls_STEPSelections_SelectFaces.def("Explore", (Standard_Boolean (STEPSelections_SelectFaces::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const ) &STEPSelections_SelectFaces::Explore, "Explores an entity, to take its faces Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
	cls_STEPSelections_SelectFaces.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectFaces::*)() const ) &STEPSelections_SelectFaces::ExploreLabel, "Returns a text defining the criterium : 'Faces'");
	cls_STEPSelections_SelectFaces.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectFaces::get_type_name, "None");
	cls_STEPSelections_SelectFaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectFaces::get_type_descriptor, "None");
	cls_STEPSelections_SelectFaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectFaces::*)() const ) &STEPSelections_SelectFaces::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectForTransfer.hxx
	py::class_<STEPSelections_SelectForTransfer, opencascade::handle<STEPSelections_SelectForTransfer>, XSControl_SelectForTransfer> cls_STEPSelections_SelectForTransfer(mod, "STEPSelections_SelectForTransfer", "None");
	cls_STEPSelections_SelectForTransfer.def(py::init<>());
	cls_STEPSelections_SelectForTransfer.def(py::init<const opencascade::handle<XSControl_TransferReader> &>(), py::arg("TR"));
	cls_STEPSelections_SelectForTransfer.def("RootResult", (Interface_EntityIterator (STEPSelections_SelectForTransfer::*)(const Interface_Graph &) const ) &STEPSelections_SelectForTransfer::RootResult, "None", py::arg("G"));
	cls_STEPSelections_SelectForTransfer.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectForTransfer::get_type_name, "None");
	cls_STEPSelections_SelectForTransfer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectForTransfer::get_type_descriptor, "None");
	cls_STEPSelections_SelectForTransfer.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectForTransfer::*)() const ) &STEPSelections_SelectForTransfer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectGSCurves.hxx
	py::class_<STEPSelections_SelectGSCurves, opencascade::handle<STEPSelections_SelectGSCurves>, IFSelect_SelectExplore> cls_STEPSelections_SelectGSCurves(mod, "STEPSelections_SelectGSCurves", "This selection returns 'curves in the geometric_set (except composite curves)'");
	cls_STEPSelections_SelectGSCurves.def(py::init<>());
	cls_STEPSelections_SelectGSCurves.def("Explore", (Standard_Boolean (STEPSelections_SelectGSCurves::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const ) &STEPSelections_SelectGSCurves::Explore, "None", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
	cls_STEPSelections_SelectGSCurves.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectGSCurves::*)() const ) &STEPSelections_SelectGSCurves::ExploreLabel, "Returns a text defining the criterium : 'Curves'");
	cls_STEPSelections_SelectGSCurves.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectGSCurves::get_type_name, "None");
	cls_STEPSelections_SelectGSCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectGSCurves::get_type_descriptor, "None");
	cls_STEPSelections_SelectGSCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectGSCurves::*)() const ) &STEPSelections_SelectGSCurves::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_SelectInstances.hxx
	py::class_<STEPSelections_SelectInstances, opencascade::handle<STEPSelections_SelectInstances>, IFSelect_SelectExplore> cls_STEPSelections_SelectInstances(mod, "STEPSelections_SelectInstances", "None");
	cls_STEPSelections_SelectInstances.def(py::init<>());
	cls_STEPSelections_SelectInstances.def("RootResult", (Interface_EntityIterator (STEPSelections_SelectInstances::*)(const Interface_Graph &) const ) &STEPSelections_SelectInstances::RootResult, "None", py::arg("G"));
	cls_STEPSelections_SelectInstances.def("Explore", (Standard_Boolean (STEPSelections_SelectInstances::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const ) &STEPSelections_SelectInstances::Explore, "None", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
	cls_STEPSelections_SelectInstances.def("ExploreLabel", (TCollection_AsciiString (STEPSelections_SelectInstances::*)() const ) &STEPSelections_SelectInstances::ExploreLabel, "Returns a text defining the criterium : 'Instances'");
	cls_STEPSelections_SelectInstances.def_static("get_type_name_", (const char * (*)()) &STEPSelections_SelectInstances::get_type_name, "None");
	cls_STEPSelections_SelectInstances.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_SelectInstances::get_type_descriptor, "None");
	cls_STEPSelections_SelectInstances.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_SelectInstances::*)() const ) &STEPSelections_SelectInstances::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\STEPSelections_HSequenceOfAssemblyLink.hxx
	py::class_<STEPSelections_HSequenceOfAssemblyLink, opencascade::handle<STEPSelections_HSequenceOfAssemblyLink>, STEPSelections_SequenceOfAssemblyLink, Standard_Transient> cls_STEPSelections_HSequenceOfAssemblyLink(mod, "STEPSelections_HSequenceOfAssemblyLink", "None");
	cls_STEPSelections_HSequenceOfAssemblyLink.def(py::init<>());
	cls_STEPSelections_HSequenceOfAssemblyLink.def(py::init<const STEPSelections_SequenceOfAssemblyLink &>(), py::arg("theOther"));
	cls_STEPSelections_HSequenceOfAssemblyLink.def("Sequence", (const STEPSelections_SequenceOfAssemblyLink & (STEPSelections_HSequenceOfAssemblyLink::*)() const ) &STEPSelections_HSequenceOfAssemblyLink::Sequence, "None");
	cls_STEPSelections_HSequenceOfAssemblyLink.def("Append", (void (STEPSelections_HSequenceOfAssemblyLink::*)(const STEPSelections_SequenceOfAssemblyLink::value_type &)) &STEPSelections_HSequenceOfAssemblyLink::Append, "None", py::arg("theItem"));
	cls_STEPSelections_HSequenceOfAssemblyLink.def("Append", (void (STEPSelections_HSequenceOfAssemblyLink::*)(STEPSelections_SequenceOfAssemblyLink &)) &STEPSelections_HSequenceOfAssemblyLink::Append, "None", py::arg("theSequence"));
	cls_STEPSelections_HSequenceOfAssemblyLink.def("ChangeSequence", (STEPSelections_SequenceOfAssemblyLink & (STEPSelections_HSequenceOfAssemblyLink::*)()) &STEPSelections_HSequenceOfAssemblyLink::ChangeSequence, "None");
	cls_STEPSelections_HSequenceOfAssemblyLink.def_static("get_type_name_", (const char * (*)()) &STEPSelections_HSequenceOfAssemblyLink::get_type_name, "None");
	cls_STEPSelections_HSequenceOfAssemblyLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPSelections_HSequenceOfAssemblyLink::get_type_descriptor, "None");
	cls_STEPSelections_HSequenceOfAssemblyLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPSelections_HSequenceOfAssemblyLink::*)() const ) &STEPSelections_HSequenceOfAssemblyLink::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<STEPSelections_SequenceOfAssemblyComponent, std::unique_ptr<STEPSelections_SequenceOfAssemblyComponent, Deleter<STEPSelections_SequenceOfAssemblyComponent>>, NCollection_BaseSequence> cls_STEPSelections_SequenceOfAssemblyComponent(mod, "STEPSelections_SequenceOfAssemblyComponent", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_STEPSelections_SequenceOfAssemblyComponent.def(py::init<>());
	cls_STEPSelections_SequenceOfAssemblyComponent.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def(py::init([] (const STEPSelections_SequenceOfAssemblyComponent &other) {return new STEPSelections_SequenceOfAssemblyComponent(other);}), "Copy constructor", py::arg("other"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("begin", (STEPSelections_SequenceOfAssemblyComponent::iterator (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("end", (STEPSelections_SequenceOfAssemblyComponent::iterator (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("cbegin", (STEPSelections_SequenceOfAssemblyComponent::const_iterator (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("cend", (STEPSelections_SequenceOfAssemblyComponent::const_iterator (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Size", (Standard_Integer (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::Size, "Number of items");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Length", (Standard_Integer (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::Length, "Number of items");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Lower", (Standard_Integer (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::Lower, "Method for consistency with other collections.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Upper", (Standard_Integer (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::Upper, "Method for consistency with other collections.");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("IsEmpty", (Standard_Boolean (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::IsEmpty, "Empty query");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Reverse", (void (STEPSelections_SequenceOfAssemblyComponent::*)()) &STEPSelections_SequenceOfAssemblyComponent::Reverse, "Reverse sequence");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Exchange", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, const Standard_Integer)) &STEPSelections_SequenceOfAssemblyComponent::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_SequenceOfAssemblyComponent::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Clear", [](STEPSelections_SequenceOfAssemblyComponent &self) -> void { return self.Clear(); });
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Clear", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &STEPSelections_SequenceOfAssemblyComponent::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Assign", (STEPSelections_SequenceOfAssemblyComponent & (STEPSelections_SequenceOfAssemblyComponent::*)(const STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("assign", (STEPSelections_SequenceOfAssemblyComponent & (STEPSelections_SequenceOfAssemblyComponent::*)(const STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Remove", (void (STEPSelections_SequenceOfAssemblyComponent::*)(STEPSelections_SequenceOfAssemblyComponent::Iterator &)) &STEPSelections_SequenceOfAssemblyComponent::Remove, "Remove one item", py::arg("thePosition"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Remove", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyComponent::Remove, "Remove one item", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Remove", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, const Standard_Integer)) &STEPSelections_SequenceOfAssemblyComponent::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Append", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::Append, "Append one item", py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Append", (void (STEPSelections_SequenceOfAssemblyComponent::*)(STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Prepend", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::Prepend, "Prepend one item", py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Prepend", (void (STEPSelections_SequenceOfAssemblyComponent::*)(STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("InsertBefore", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("InsertBefore", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyComponent::*)(STEPSelections_SequenceOfAssemblyComponent::Iterator &, const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("InsertAfter", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Split", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, STEPSelections_SequenceOfAssemblyComponent &)) &STEPSelections_SequenceOfAssemblyComponent::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("First", (const opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::First, "First item access");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("ChangeFirst", (opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)()) &STEPSelections_SequenceOfAssemblyComponent::ChangeFirst, "First item access");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Last", (const opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)() const ) &STEPSelections_SequenceOfAssemblyComponent::Last, "Last item access");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("ChangeLast", (opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)()) &STEPSelections_SequenceOfAssemblyComponent::ChangeLast, "Last item access");
	cls_STEPSelections_SequenceOfAssemblyComponent.def("Value", (const opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer) const ) &STEPSelections_SequenceOfAssemblyComponent::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("__call__", (const opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer) const ) &STEPSelections_SequenceOfAssemblyComponent::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("ChangeValue", (opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyComponent::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("__call__", (opencascade::handle<STEPSelections_AssemblyComponent> & (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer)) &STEPSelections_SequenceOfAssemblyComponent::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("SetValue", (void (STEPSelections_SequenceOfAssemblyComponent::*)(const Standard_Integer, const opencascade::handle<STEPSelections_AssemblyComponent> &)) &STEPSelections_SequenceOfAssemblyComponent::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_STEPSelections_SequenceOfAssemblyComponent.def("__iter__", [](const STEPSelections_SequenceOfAssemblyComponent &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
