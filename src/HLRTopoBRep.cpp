#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <HLRTopoBRep_Data.hxx>
#include <HLRAlgo_Projector.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <TopTools_ListOfShape.hxx>
#include <HLRTopoBRep_FaceData.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <HLRTopoBRep_DataMapOfShapeFaceData.hxx>
#include <HLRTopoBRep_VData.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <HLRTopoBRep_ListOfVData.hxx>
#include <HLRTopoBRep_MapOfShapeListOfVData.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <Contap_Contour.hxx>
#include <HLRTopoBRep_DSFiller.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Line.hxx>
#include <HLRTopoBRep_FaceIsoLiner.hxx>

PYBIND11_MODULE(HLRTopoBRep, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.HLRAlgo");
	py::module::import("OCCT.BRepTopAdaptor");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Contap");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_OutLiner.hxx
	py::class_<HLRTopoBRep_OutLiner, opencascade::handle<HLRTopoBRep_OutLiner>, Standard_Transient> cls_HLRTopoBRep_OutLiner(mod, "HLRTopoBRep_OutLiner", "None");
	cls_HLRTopoBRep_OutLiner.def(py::init<>());
	cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &>(), py::arg("OriSh"));
	cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("OriS"), py::arg("OutS"));
	cls_HLRTopoBRep_OutLiner.def("OriginalShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OriginalShape, "None", py::arg("OriS"));
	cls_HLRTopoBRep_OutLiner.def("OriginalShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OriginalShape, "None");
	cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OutLinedShape, "None", py::arg("OutS"));
	cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OutLinedShape, "None");
	cls_HLRTopoBRep_OutLiner.def("DataStructure", (HLRTopoBRep_Data & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::DataStructure, "None");
	cls_HLRTopoBRep_OutLiner.def("Fill", (void (HLRTopoBRep_OutLiner::*)(const HLRAlgo_Projector &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_OutLiner::Fill, "None", py::arg("P"), py::arg("MST"), py::arg("nbIso"));
	cls_HLRTopoBRep_OutLiner.def_static("get_type_name_", (const char * (*)()) &HLRTopoBRep_OutLiner::get_type_name, "None");
	cls_HLRTopoBRep_OutLiner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRTopoBRep_OutLiner::get_type_descriptor, "None");
	cls_HLRTopoBRep_OutLiner.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRTopoBRep_OutLiner::*)() const ) &HLRTopoBRep_OutLiner::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_FaceData.hxx
	py::class_<HLRTopoBRep_FaceData, std::unique_ptr<HLRTopoBRep_FaceData, Deleter<HLRTopoBRep_FaceData>>> cls_HLRTopoBRep_FaceData(mod, "HLRTopoBRep_FaceData", "Contains the 3 ListOfShape of a Face ( Internal OutLines, OutLines on restriction and IsoLines ).");
	cls_HLRTopoBRep_FaceData.def(py::init<>());
	cls_HLRTopoBRep_FaceData.def("FaceIntL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const ) &HLRTopoBRep_FaceData::FaceIntL, "None");
	cls_HLRTopoBRep_FaceData.def("FaceOutL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const ) &HLRTopoBRep_FaceData::FaceOutL, "None");
	cls_HLRTopoBRep_FaceData.def("FaceIsoL", (const TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)() const ) &HLRTopoBRep_FaceData::FaceIsoL, "None");
	cls_HLRTopoBRep_FaceData.def("AddIntL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIntL, "None");
	cls_HLRTopoBRep_FaceData.def("AddOutL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddOutL, "None");
	cls_HLRTopoBRep_FaceData.def("AddIsoL", (TopTools_ListOfShape & (HLRTopoBRep_FaceData::*)()) &HLRTopoBRep_FaceData::AddIsoL, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_VData.hxx
	py::class_<HLRTopoBRep_VData, std::unique_ptr<HLRTopoBRep_VData, Deleter<HLRTopoBRep_VData>>> cls_HLRTopoBRep_VData(mod, "HLRTopoBRep_VData", "None");
	cls_HLRTopoBRep_VData.def(py::init<>());
	cls_HLRTopoBRep_VData.def(py::init<const Standard_Real, const TopoDS_Shape &>(), py::arg("P"), py::arg("V"));
	cls_HLRTopoBRep_VData.def("Parameter", (Standard_Real (HLRTopoBRep_VData::*)() const ) &HLRTopoBRep_VData::Parameter, "None");
	cls_HLRTopoBRep_VData.def("Vertex", (const TopoDS_Shape & (HLRTopoBRep_VData::*)() const ) &HLRTopoBRep_VData::Vertex, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_Data.hxx
	py::class_<HLRTopoBRep_Data, std::unique_ptr<HLRTopoBRep_Data, Deleter<HLRTopoBRep_Data>>> cls_HLRTopoBRep_Data(mod, "HLRTopoBRep_Data", "Stores the results of the OutLine and IsoLine processes.");
	cls_HLRTopoBRep_Data.def(py::init<>());
	cls_HLRTopoBRep_Data.def("Clear", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::Clear, "Clear of all the maps.");
	cls_HLRTopoBRep_Data.def("Clean", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::Clean, "Clear of all the data not needed during and after the hiding process.");
	cls_HLRTopoBRep_Data.def("EdgeHasSplE", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Edge &) const ) &HLRTopoBRep_Data::EdgeHasSplE, "Returns True if the Edge is split.", py::arg("E"));
	cls_HLRTopoBRep_Data.def("FaceHasIntL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceHasIntL, "Returns True if the Face has internal outline.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("FaceHasOutL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceHasOutL, "Returns True if the Face has outlines on restriction.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("FaceHasIsoL", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceHasIsoL, "Returns True if the Face has isolines.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("IsSplEEdgeEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Edge &, const TopoDS_Edge &) const ) &HLRTopoBRep_Data::IsSplEEdgeEdge, "None", py::arg("E1"), py::arg("E2"));
	cls_HLRTopoBRep_Data.def("IsIntLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const ) &HLRTopoBRep_Data::IsIntLFaceEdge, "None", py::arg("F"), py::arg("E"));
	cls_HLRTopoBRep_Data.def("IsOutLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const ) &HLRTopoBRep_Data::IsOutLFaceEdge, "None", py::arg("F"), py::arg("E"));
	cls_HLRTopoBRep_Data.def("IsIsoLFaceEdge", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Face &, const TopoDS_Edge &) const ) &HLRTopoBRep_Data::IsIsoLFaceEdge, "None", py::arg("F"), py::arg("E"));
	cls_HLRTopoBRep_Data.def("NewSOldS", (TopoDS_Shape (HLRTopoBRep_Data::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_Data::NewSOldS, "None", py::arg("New"));
	cls_HLRTopoBRep_Data.def("EdgeSplE", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Edge &) const ) &HLRTopoBRep_Data::EdgeSplE, "Returns the list of the edges.", py::arg("E"));
	cls_HLRTopoBRep_Data.def("FaceIntL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceIntL, "Returns the list of the internal OutLines.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("FaceOutL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceOutL, "Returns the list of the OutLines on restriction.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("FaceIsoL", (const TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &) const ) &HLRTopoBRep_Data::FaceIsoL, "Returns the list of the IsoLines.", py::arg("F"));
	cls_HLRTopoBRep_Data.def("IsOutV", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Vertex &) const ) &HLRTopoBRep_Data::IsOutV, "Returns True if V is an outline vertex on a restriction.", py::arg("V"));
	cls_HLRTopoBRep_Data.def("IsIntV", (Standard_Boolean (HLRTopoBRep_Data::*)(const TopoDS_Vertex &) const ) &HLRTopoBRep_Data::IsIntV, "Returns True if V is an internal outline vertex.", py::arg("V"));
	cls_HLRTopoBRep_Data.def("AddOldS", (void (HLRTopoBRep_Data::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &HLRTopoBRep_Data::AddOldS, "None", py::arg("NewS"), py::arg("OldS"));
	cls_HLRTopoBRep_Data.def("AddSplE", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Edge &)) &HLRTopoBRep_Data::AddSplE, "None", py::arg("E"));
	cls_HLRTopoBRep_Data.def("AddIntL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddIntL, "None", py::arg("F"));
	cls_HLRTopoBRep_Data.def("AddOutL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddOutL, "None", py::arg("F"));
	cls_HLRTopoBRep_Data.def("AddIsoL", (TopTools_ListOfShape & (HLRTopoBRep_Data::*)(const TopoDS_Face &)) &HLRTopoBRep_Data::AddIsoL, "None", py::arg("F"));
	cls_HLRTopoBRep_Data.def("AddOutV", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &)) &HLRTopoBRep_Data::AddOutV, "None", py::arg("V"));
	cls_HLRTopoBRep_Data.def("AddIntV", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &)) &HLRTopoBRep_Data::AddIntV, "None", py::arg("V"));
	cls_HLRTopoBRep_Data.def("InitEdge", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::InitEdge, "None");
	cls_HLRTopoBRep_Data.def("MoreEdge", (Standard_Boolean (HLRTopoBRep_Data::*)() const ) &HLRTopoBRep_Data::MoreEdge, "None");
	cls_HLRTopoBRep_Data.def("NextEdge", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::NextEdge, "None");
	cls_HLRTopoBRep_Data.def("Edge", (const TopoDS_Edge & (HLRTopoBRep_Data::*)() const ) &HLRTopoBRep_Data::Edge, "None");
	cls_HLRTopoBRep_Data.def("InitVertex", (void (HLRTopoBRep_Data::*)(const TopoDS_Edge &)) &HLRTopoBRep_Data::InitVertex, "Start an iteration on the vertices of E.", py::arg("E"));
	cls_HLRTopoBRep_Data.def("MoreVertex", (Standard_Boolean (HLRTopoBRep_Data::*)() const ) &HLRTopoBRep_Data::MoreVertex, "None");
	cls_HLRTopoBRep_Data.def("NextVertex", (void (HLRTopoBRep_Data::*)()) &HLRTopoBRep_Data::NextVertex, "None");
	cls_HLRTopoBRep_Data.def("Vertex", (const TopoDS_Vertex & (HLRTopoBRep_Data::*)() const ) &HLRTopoBRep_Data::Vertex, "None");
	cls_HLRTopoBRep_Data.def("Parameter", (Standard_Real (HLRTopoBRep_Data::*)() const ) &HLRTopoBRep_Data::Parameter, "None");
	cls_HLRTopoBRep_Data.def("InsertBefore", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &, const Standard_Real)) &HLRTopoBRep_Data::InsertBefore, "Insert before the current position.", py::arg("V"), py::arg("P"));
	cls_HLRTopoBRep_Data.def("Append", (void (HLRTopoBRep_Data::*)(const TopoDS_Vertex &, const Standard_Real)) &HLRTopoBRep_Data::Append, "None", py::arg("V"), py::arg("P"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_DSFiller.hxx
	py::class_<HLRTopoBRep_DSFiller, std::unique_ptr<HLRTopoBRep_DSFiller, Deleter<HLRTopoBRep_DSFiller>>> cls_HLRTopoBRep_DSFiller(mod, "HLRTopoBRep_DSFiller", "Provides methods to fill a HLRTopoBRep_Data.");
	cls_HLRTopoBRep_DSFiller.def(py::init<>());
	cls_HLRTopoBRep_DSFiller.def_static("Insert_", (void (*)(const TopoDS_Shape &, Contap_Contour &, HLRTopoBRep_Data &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_DSFiller::Insert, "Stores in <DS> the outlines of <S> using the current outliner and stores the isolines in <DS> using a Hatcher.", py::arg("S"), py::arg("FO"), py::arg("DS"), py::arg("MST"), py::arg("nbIso"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_FaceIsoLiner.hxx
	py::class_<HLRTopoBRep_FaceIsoLiner, std::unique_ptr<HLRTopoBRep_FaceIsoLiner, Deleter<HLRTopoBRep_FaceIsoLiner>>> cls_HLRTopoBRep_FaceIsoLiner(mod, "HLRTopoBRep_FaceIsoLiner", "None");
	cls_HLRTopoBRep_FaceIsoLiner.def(py::init<>());
	cls_HLRTopoBRep_FaceIsoLiner.def_static("Perform_", (void (*)(const Standard_Integer, const TopoDS_Face &, HLRTopoBRep_Data &, const Standard_Integer)) &HLRTopoBRep_FaceIsoLiner::Perform, "None", py::arg("FI"), py::arg("F"), py::arg("DS"), py::arg("nbIsos"));
	cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeVertex_", (TopoDS_Vertex (*)(const TopoDS_Edge &, const gp_Pnt &, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeVertex, "None", py::arg("E"), py::arg("P"), py::arg("Par"), py::arg("Tol"), py::arg("DS"));
	cls_HLRTopoBRep_FaceIsoLiner.def_static("MakeIsoLine_", (void (*)(const TopoDS_Face &, const opencascade::handle<Geom2d_Line> &, TopoDS_Vertex &, TopoDS_Vertex &, const Standard_Real, const Standard_Real, const Standard_Real, HLRTopoBRep_Data &)) &HLRTopoBRep_FaceIsoLiner::MakeIsoLine, "None", py::arg("F"), py::arg("Iso"), py::arg("V1"), py::arg("V2"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("DS"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<HLRTopoBRep_DataMapOfShapeFaceData, std::unique_ptr<HLRTopoBRep_DataMapOfShapeFaceData, Deleter<HLRTopoBRep_DataMapOfShapeFaceData>>, NCollection_BaseMap> cls_HLRTopoBRep_DataMapOfShapeFaceData(mod, "HLRTopoBRep_DataMapOfShapeFaceData", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def(py::init<>());
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def(py::init([] (const HLRTopoBRep_DataMapOfShapeFaceData &other) {return new HLRTopoBRep_DataMapOfShapeFaceData(other);}), "Copy constructor", py::arg("other"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("begin", (HLRTopoBRep_DataMapOfShapeFaceData::iterator (HLRTopoBRep_DataMapOfShapeFaceData::*)() const ) &HLRTopoBRep_DataMapOfShapeFaceData::begin, "Returns an iterator pointing to the first element in the map.");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("end", (HLRTopoBRep_DataMapOfShapeFaceData::iterator (HLRTopoBRep_DataMapOfShapeFaceData::*)() const ) &HLRTopoBRep_DataMapOfShapeFaceData::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("cbegin", (HLRTopoBRep_DataMapOfShapeFaceData::const_iterator (HLRTopoBRep_DataMapOfShapeFaceData::*)() const ) &HLRTopoBRep_DataMapOfShapeFaceData::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("cend", (HLRTopoBRep_DataMapOfShapeFaceData::const_iterator (HLRTopoBRep_DataMapOfShapeFaceData::*)() const ) &HLRTopoBRep_DataMapOfShapeFaceData::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Exchange", (void (HLRTopoBRep_DataMapOfShapeFaceData::*)(HLRTopoBRep_DataMapOfShapeFaceData &)) &HLRTopoBRep_DataMapOfShapeFaceData::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Assign", (HLRTopoBRep_DataMapOfShapeFaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const HLRTopoBRep_DataMapOfShapeFaceData &)) &HLRTopoBRep_DataMapOfShapeFaceData::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("assign", (HLRTopoBRep_DataMapOfShapeFaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const HLRTopoBRep_DataMapOfShapeFaceData &)) &HLRTopoBRep_DataMapOfShapeFaceData::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("ReSize", (void (HLRTopoBRep_DataMapOfShapeFaceData::*)(const Standard_Integer)) &HLRTopoBRep_DataMapOfShapeFaceData::ReSize, "ReSize", py::arg("N"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Bind", (Standard_Boolean (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &, const HLRTopoBRep_FaceData &)) &HLRTopoBRep_DataMapOfShapeFaceData::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Bound", (HLRTopoBRep_FaceData * (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &, const HLRTopoBRep_FaceData &)) &HLRTopoBRep_DataMapOfShapeFaceData::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("IsBound", (Standard_Boolean (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_DataMapOfShapeFaceData::IsBound, "IsBound", py::arg("theKey"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("UnBind", (Standard_Boolean (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &)) &HLRTopoBRep_DataMapOfShapeFaceData::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Seek", (const HLRTopoBRep_FaceData * (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_DataMapOfShapeFaceData::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Find", (const HLRTopoBRep_FaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_DataMapOfShapeFaceData::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Find", (Standard_Boolean (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &, HLRTopoBRep_FaceData &) const ) &HLRTopoBRep_DataMapOfShapeFaceData::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("__call__", (const HLRTopoBRep_FaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_DataMapOfShapeFaceData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_DataMapOfShapeFaceData.def("ChangeSeek", (HLRTopoBRep_FaceData * (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &)) &HLRTopoBRep_DataMapOfShapeFaceData::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("ChangeFind", (HLRTopoBRep_FaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &)) &HLRTopoBRep_DataMapOfShapeFaceData::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("__call__", (HLRTopoBRep_FaceData & (HLRTopoBRep_DataMapOfShapeFaceData::*)(const TopoDS_Shape &)) &HLRTopoBRep_DataMapOfShapeFaceData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Clear", [](HLRTopoBRep_DataMapOfShapeFaceData &self) -> void { return self.Clear(); });
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Clear", (void (HLRTopoBRep_DataMapOfShapeFaceData::*)(const Standard_Boolean)) &HLRTopoBRep_DataMapOfShapeFaceData::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Clear", (void (HLRTopoBRep_DataMapOfShapeFaceData::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HLRTopoBRep_DataMapOfShapeFaceData::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("Size", (Standard_Integer (HLRTopoBRep_DataMapOfShapeFaceData::*)() const ) &HLRTopoBRep_DataMapOfShapeFaceData::Size, "Size");
	cls_HLRTopoBRep_DataMapOfShapeFaceData.def("__iter__", [](const HLRTopoBRep_DataMapOfShapeFaceData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_DataMapOfShapeFaceData.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<HLRTopoBRep_ListOfVData, std::unique_ptr<HLRTopoBRep_ListOfVData, Deleter<HLRTopoBRep_ListOfVData>>, NCollection_BaseList> cls_HLRTopoBRep_ListOfVData(mod, "HLRTopoBRep_ListOfVData", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_HLRTopoBRep_ListOfVData.def(py::init<>());
	cls_HLRTopoBRep_ListOfVData.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_HLRTopoBRep_ListOfVData.def(py::init([] (const HLRTopoBRep_ListOfVData &other) {return new HLRTopoBRep_ListOfVData(other);}), "Copy constructor", py::arg("other"));
	cls_HLRTopoBRep_ListOfVData.def("begin", (HLRTopoBRep_ListOfVData::iterator (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::begin, "Returns an iterator pointing to the first element in the list.");
	cls_HLRTopoBRep_ListOfVData.def("end", (HLRTopoBRep_ListOfVData::iterator (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_HLRTopoBRep_ListOfVData.def("cbegin", (HLRTopoBRep_ListOfVData::const_iterator (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_HLRTopoBRep_ListOfVData.def("cend", (HLRTopoBRep_ListOfVData::const_iterator (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_HLRTopoBRep_ListOfVData.def("Size", (Standard_Integer (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::Size, "Size - Number of items");
	cls_HLRTopoBRep_ListOfVData.def("Assign", (HLRTopoBRep_ListOfVData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_ListOfVData::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_HLRTopoBRep_ListOfVData.def("assign", (HLRTopoBRep_ListOfVData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_ListOfVData::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_HLRTopoBRep_ListOfVData.def("Clear", [](HLRTopoBRep_ListOfVData &self) -> void { return self.Clear(); });
	cls_HLRTopoBRep_ListOfVData.def("Clear", (void (HLRTopoBRep_ListOfVData::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HLRTopoBRep_ListOfVData::Clear, "Clear this list", py::arg("theAllocator"));
	cls_HLRTopoBRep_ListOfVData.def("First", (const HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::First, "First item");
	cls_HLRTopoBRep_ListOfVData.def("First", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)()) &HLRTopoBRep_ListOfVData::First, "First item (non-const)");
	cls_HLRTopoBRep_ListOfVData.def("Last", (const HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)() const ) &HLRTopoBRep_ListOfVData::Last, "Last item");
	cls_HLRTopoBRep_ListOfVData.def("Last", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)()) &HLRTopoBRep_ListOfVData::Last, "Last item (non-const)");
	cls_HLRTopoBRep_ListOfVData.def("Append", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_VData &)) &HLRTopoBRep_ListOfVData::Append, "Append one item at the end", py::arg("theItem"));
	cls_HLRTopoBRep_ListOfVData.def("Append", (void (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_VData &, HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("Append", (void (HLRTopoBRep_ListOfVData::*)(HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_ListOfVData::Append, "Append another list at the end", py::arg("theOther"));
	cls_HLRTopoBRep_ListOfVData.def("Prepend", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_VData &)) &HLRTopoBRep_ListOfVData::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_HLRTopoBRep_ListOfVData.def("Prepend", (void (HLRTopoBRep_ListOfVData::*)(HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_ListOfVData::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_HLRTopoBRep_ListOfVData.def("RemoveFirst", (void (HLRTopoBRep_ListOfVData::*)()) &HLRTopoBRep_ListOfVData::RemoveFirst, "RemoveFirst item");
	cls_HLRTopoBRep_ListOfVData.def("Remove", (void (HLRTopoBRep_ListOfVData::*)(HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("InsertBefore", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_VData &, HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("InsertBefore", (void (HLRTopoBRep_ListOfVData::*)(HLRTopoBRep_ListOfVData &, HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("InsertAfter", (HLRTopoBRep_VData & (HLRTopoBRep_ListOfVData::*)(const HLRTopoBRep_VData &, HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("InsertAfter", (void (HLRTopoBRep_ListOfVData::*)(HLRTopoBRep_ListOfVData &, HLRTopoBRep_ListOfVData::Iterator &)) &HLRTopoBRep_ListOfVData::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_HLRTopoBRep_ListOfVData.def("Reverse", (void (HLRTopoBRep_ListOfVData::*)()) &HLRTopoBRep_ListOfVData::Reverse, "Reverse the list");
	cls_HLRTopoBRep_ListOfVData.def("__iter__", [](const HLRTopoBRep_ListOfVData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<HLRTopoBRep_ListIteratorOfListOfVData, std::unique_ptr<HLRTopoBRep_ListIteratorOfListOfVData, Deleter<HLRTopoBRep_ListIteratorOfListOfVData>>> cls_HLRTopoBRep_ListIteratorOfListOfVData(mod, "HLRTopoBRep_ListIteratorOfListOfVData", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def(py::init<>());
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def("More", (Standard_Boolean (HLRTopoBRep_ListIteratorOfListOfVData::*)() const ) &HLRTopoBRep_ListIteratorOfListOfVData::More, "Check end");
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def("Next", (void (HLRTopoBRep_ListIteratorOfListOfVData::*)()) &HLRTopoBRep_ListIteratorOfListOfVData::Next, "Make step");
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def("Value", (const HLRTopoBRep_VData & (HLRTopoBRep_ListIteratorOfListOfVData::*)() const ) &HLRTopoBRep_ListIteratorOfListOfVData::Value, "Constant Value access");
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def("Value", (HLRTopoBRep_VData & (HLRTopoBRep_ListIteratorOfListOfVData::*)()) &HLRTopoBRep_ListIteratorOfListOfVData::Value, "Non-const Value access");
	cls_HLRTopoBRep_ListIteratorOfListOfVData.def("ChangeValue", (HLRTopoBRep_VData & (HLRTopoBRep_ListIteratorOfListOfVData::*)() const ) &HLRTopoBRep_ListIteratorOfListOfVData::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<HLRTopoBRep_MapOfShapeListOfVData, std::unique_ptr<HLRTopoBRep_MapOfShapeListOfVData, Deleter<HLRTopoBRep_MapOfShapeListOfVData>>, NCollection_BaseMap> cls_HLRTopoBRep_MapOfShapeListOfVData(mod, "HLRTopoBRep_MapOfShapeListOfVData", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def(py::init<>());
	cls_HLRTopoBRep_MapOfShapeListOfVData.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def(py::init([] (const HLRTopoBRep_MapOfShapeListOfVData &other) {return new HLRTopoBRep_MapOfShapeListOfVData(other);}), "Copy constructor", py::arg("other"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("begin", (HLRTopoBRep_MapOfShapeListOfVData::iterator (HLRTopoBRep_MapOfShapeListOfVData::*)() const ) &HLRTopoBRep_MapOfShapeListOfVData::begin, "Returns an iterator pointing to the first element in the map.");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("end", (HLRTopoBRep_MapOfShapeListOfVData::iterator (HLRTopoBRep_MapOfShapeListOfVData::*)() const ) &HLRTopoBRep_MapOfShapeListOfVData::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("cbegin", (HLRTopoBRep_MapOfShapeListOfVData::const_iterator (HLRTopoBRep_MapOfShapeListOfVData::*)() const ) &HLRTopoBRep_MapOfShapeListOfVData::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("cend", (HLRTopoBRep_MapOfShapeListOfVData::const_iterator (HLRTopoBRep_MapOfShapeListOfVData::*)() const ) &HLRTopoBRep_MapOfShapeListOfVData::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Exchange", (void (HLRTopoBRep_MapOfShapeListOfVData::*)(HLRTopoBRep_MapOfShapeListOfVData &)) &HLRTopoBRep_MapOfShapeListOfVData::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Assign", (HLRTopoBRep_MapOfShapeListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const HLRTopoBRep_MapOfShapeListOfVData &)) &HLRTopoBRep_MapOfShapeListOfVData::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("assign", (HLRTopoBRep_MapOfShapeListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const HLRTopoBRep_MapOfShapeListOfVData &)) &HLRTopoBRep_MapOfShapeListOfVData::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("ReSize", (void (HLRTopoBRep_MapOfShapeListOfVData::*)(const Standard_Integer)) &HLRTopoBRep_MapOfShapeListOfVData::ReSize, "ReSize", py::arg("N"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Bind", (Standard_Boolean (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &, const HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_MapOfShapeListOfVData::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_HLRTopoBRep_MapOfShapeListOfVData.def("Bound", (HLRTopoBRep_ListOfVData * (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &, const HLRTopoBRep_ListOfVData &)) &HLRTopoBRep_MapOfShapeListOfVData::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("IsBound", (Standard_Boolean (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_MapOfShapeListOfVData::IsBound, "IsBound", py::arg("theKey"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("UnBind", (Standard_Boolean (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &)) &HLRTopoBRep_MapOfShapeListOfVData::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_MapOfShapeListOfVData.def("Seek", (const HLRTopoBRep_ListOfVData * (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_MapOfShapeListOfVData::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_MapOfShapeListOfVData.def("Find", (const HLRTopoBRep_ListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_MapOfShapeListOfVData::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_MapOfShapeListOfVData.def("Find", (Standard_Boolean (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &, HLRTopoBRep_ListOfVData &) const ) &HLRTopoBRep_MapOfShapeListOfVData::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("__call__", (const HLRTopoBRep_ListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &) const ) &HLRTopoBRep_MapOfShapeListOfVData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_HLRTopoBRep_MapOfShapeListOfVData.def("ChangeSeek", (HLRTopoBRep_ListOfVData * (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &)) &HLRTopoBRep_MapOfShapeListOfVData::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("ChangeFind", (HLRTopoBRep_ListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &)) &HLRTopoBRep_MapOfShapeListOfVData::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("__call__", (HLRTopoBRep_ListOfVData & (HLRTopoBRep_MapOfShapeListOfVData::*)(const TopoDS_Shape &)) &HLRTopoBRep_MapOfShapeListOfVData::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Clear", [](HLRTopoBRep_MapOfShapeListOfVData &self) -> void { return self.Clear(); });
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Clear", (void (HLRTopoBRep_MapOfShapeListOfVData::*)(const Standard_Boolean)) &HLRTopoBRep_MapOfShapeListOfVData::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Clear", (void (HLRTopoBRep_MapOfShapeListOfVData::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &HLRTopoBRep_MapOfShapeListOfVData::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("Size", (Standard_Integer (HLRTopoBRep_MapOfShapeListOfVData::*)() const ) &HLRTopoBRep_MapOfShapeListOfVData::Size, "Size");
	cls_HLRTopoBRep_MapOfShapeListOfVData.def("__iter__", [](const HLRTopoBRep_MapOfShapeListOfVData &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\HLRTopoBRep_MapOfShapeListOfVData.hxx

}
