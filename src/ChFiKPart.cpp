#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <ChFiDS_SurfData.hxx>

#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_SurfData.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFiDS_Spine.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFiKPart_ComputeData.hxx>
#include <ChFiKPart_ComputeData_ChAsymPlnPln.hxx>
#include <gp_Pln.hxx>
#include <gp_Lin.hxx>
#include <ChFiKPart_ComputeData_ChPlnPln.hxx>
#include <ChFiKPart_ComputeData_CS.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Circ.hxx>
#include <ChFiKPart_ComputeData_Fcts.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <ChFiKPart_ComputeData_FilPlnPln.hxx>
#include <ChFiKPart_ComputeData_Rotule.hxx>
#include <ChFiKPart_ComputeData_Sphere.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <ChFiKPart_RstMap.hxx>

PYBIND11_MODULE(ChFiKPart, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopOpeBRepDS");
	py::module::import("OCCT.ChFiDS");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAdaptor");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_ChAsymPlnPln.hxx
	mod.def("ChFiKPart_MakeChAsym", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation, const Standard_Boolean)) &ChFiKPart_MakeChAsym, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Dis"), py::arg("Angle"), py::arg("Spine"), py::arg("First"), py::arg("Of1"), py::arg("DisOnP1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_ChPlnPln.hxx
	mod.def("ChFiKPart_MakeChamfer", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeChamfer, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Dis1"), py::arg("Dis2"), py::arg("Spine"), py::arg("First"), py::arg("Of1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_CS.hxx
	mod.def("ChFiKPart_CornerSpine", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, gp_Cylinder &, gp_Circ &, Standard_Real &, Standard_Real &)) &ChFiKPart_CornerSpine, "None", py::arg("S1"), py::arg("S2"), py::arg("P1S1"), py::arg("P2S1"), py::arg("P1S2"), py::arg("P2S2"), py::arg("R"), py::arg("cyl"), py::arg("circ"), py::arg("First"), py::arg("Last"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_InPeriod", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &ChFiKPart_InPeriod, "None", py::arg("U"), py::arg("UFirst"), py::arg("ULast"), py::arg("Eps"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_PCurve", (opencascade::handle<Geom2d_BSplineCurve> (*)(const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &ChFiKPart_PCurve, "None", py::arg("UV1"), py::arg("UV2"), py::arg("Pardeb"), py::arg("Parfin"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_ProjPC", (void (*)(const GeomAdaptor_Curve &, const GeomAdaptor_Surface &, opencascade::handle<Geom2d_Curve> &)) &ChFiKPart_ProjPC, "None", py::arg("Cg"), py::arg("Sg"), py::arg("Pcurv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_IndexCurveInDS", (Standard_Integer (*)(const opencascade::handle<Geom_Curve> &, TopOpeBRepDS_DataStructure &)) &ChFiKPart_IndexCurveInDS, "None", py::arg("C"), py::arg("DStr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Fcts.hxx
	mod.def("ChFiKPart_IndexSurfaceInDS", (Standard_Integer (*)(const opencascade::handle<Geom_Surface> &, TopOpeBRepDS_DataStructure &)) &ChFiKPart_IndexSurfaceInDS, "None", py::arg("S"), py::arg("DStr"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_FilPlnPln.hxx
	mod.def("ChFiKPart_MakeFillet", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Lin &, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeFillet, "None", py::arg("DStr"), py::arg("Data"), py::arg("Pl1"), py::arg("Pl2"), py::arg("Or1"), py::arg("Or2"), py::arg("Radius"), py::arg("Spine"), py::arg("First"), py::arg("Of1"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Rotule.hxx
	mod.def("ChFiKPart_MakeRotule", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const gp_Pln &, const gp_Pln &, const gp_Pln &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const TopAbs_Orientation)) &ChFiKPart_MakeRotule, "None", py::arg("DStr"), py::arg("Data"), py::arg("pl"), py::arg("pl1"), py::arg("pl2"), py::arg("opl"), py::arg("opl1"), py::arg("opl2"), py::arg("r"), py::arg("ofpl"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData_Sphere.hxx
	mod.def("ChFiKPart_Sphere", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_Sphere, "None", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("Rad"), py::arg("PS1"), py::arg("P1S2"), py::arg("P2S2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_ComputeData.hxx
	py::class_<ChFiKPart_ComputeData, std::unique_ptr<ChFiKPart_ComputeData, Deleter<ChFiKPart_ComputeData>>> cls_ChFiKPart_ComputeData(mod, "ChFiKPart_ComputeData", "Methodes de classe permettant de remplir une SurfData dans les cas particuliers de conges suivants: - cylindre entre 2 surfaces planes, - tore/sphere entre un plan et un cylindre othogonal, - tore/sphere entre un plan et un cone othogonal,");
	cls_ChFiKPart_ComputeData.def(py::init<>());
	cls_ChFiKPart_ComputeData.def_static("Compute_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const opencascade::handle<ChFiDS_Spine> &, const Standard_Integer)) &ChFiKPart_ComputeData::Compute, "Computes a simple fillet in several particular cases.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("Or1"), py::arg("Or2"), py::arg("Sp"), py::arg("Iedge"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric or spheric corner fillet.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("minRad"), py::arg("majRad"), py::arg("P1S1"), py::arg("P2S1"), py::arg("P1S2"), py::arg("P2S2"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiKPart_ComputeData::ComputeCorner, "Computes spheric corner fillet with non iso pcurve on S2.", py::arg("DStr"), py::arg("Data"), py::arg("S1"), py::arg("S2"), py::arg("OrFace1"), py::arg("OrFace2"), py::arg("Or1"), py::arg("Or2"), py::arg("Rad"), py::arg("PS1"), py::arg("P1S2"), py::arg("P2S2"));
	cls_ChFiKPart_ComputeData.def_static("ComputeCorner_", (Standard_Boolean (*)(TopOpeBRepDS_DataStructure &, const opencascade::handle<ChFiDS_SurfData> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation, const Standard_Real)) &ChFiKPart_ComputeData::ComputeCorner, "Computes a toric corner rotule.", py::arg("DStr"), py::arg("Data"), py::arg("S"), py::arg("S1"), py::arg("S2"), py::arg("OfS"), py::arg("OS"), py::arg("OS1"), py::arg("OS2"), py::arg("Radius"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<ChFiKPart_RstMap, std::unique_ptr<ChFiKPart_RstMap, Deleter<ChFiKPart_RstMap>>, NCollection_BaseMap> cls_ChFiKPart_RstMap(mod, "ChFiKPart_RstMap", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_ChFiKPart_RstMap.def(py::init<>());
	cls_ChFiKPart_RstMap.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_ChFiKPart_RstMap.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_ChFiKPart_RstMap.def(py::init([] (const ChFiKPart_RstMap &other) {return new ChFiKPart_RstMap(other);}), "Copy constructor", py::arg("other"));
	cls_ChFiKPart_RstMap.def("begin", (ChFiKPart_RstMap::iterator (ChFiKPart_RstMap::*)() const ) &ChFiKPart_RstMap::begin, "Returns an iterator pointing to the first element in the map.");
	cls_ChFiKPart_RstMap.def("end", (ChFiKPart_RstMap::iterator (ChFiKPart_RstMap::*)() const ) &ChFiKPart_RstMap::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_ChFiKPart_RstMap.def("cbegin", (ChFiKPart_RstMap::const_iterator (ChFiKPart_RstMap::*)() const ) &ChFiKPart_RstMap::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_ChFiKPart_RstMap.def("cend", (ChFiKPart_RstMap::const_iterator (ChFiKPart_RstMap::*)() const ) &ChFiKPart_RstMap::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_ChFiKPart_RstMap.def("Exchange", (void (ChFiKPart_RstMap::*)(ChFiKPart_RstMap &)) &ChFiKPart_RstMap::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_ChFiKPart_RstMap.def("Assign", (ChFiKPart_RstMap & (ChFiKPart_RstMap::*)(const ChFiKPart_RstMap &)) &ChFiKPart_RstMap::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_ChFiKPart_RstMap.def("assign", (ChFiKPart_RstMap & (ChFiKPart_RstMap::*)(const ChFiKPart_RstMap &)) &ChFiKPart_RstMap::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_ChFiKPart_RstMap.def("ReSize", (void (ChFiKPart_RstMap::*)(const Standard_Integer)) &ChFiKPart_RstMap::ReSize, "ReSize", py::arg("N"));
	cls_ChFiKPart_RstMap.def("Bind", (Standard_Boolean (ChFiKPart_RstMap::*)(const Standard_Integer &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &ChFiKPart_RstMap::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_ChFiKPart_RstMap.def("Bound", (opencascade::handle<Adaptor2d_HCurve2d> * (ChFiKPart_RstMap::*)(const Standard_Integer &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &ChFiKPart_RstMap::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_ChFiKPart_RstMap.def("IsBound", (Standard_Boolean (ChFiKPart_RstMap::*)(const Standard_Integer &) const ) &ChFiKPart_RstMap::IsBound, "IsBound", py::arg("theKey"));
	cls_ChFiKPart_RstMap.def("UnBind", (Standard_Boolean (ChFiKPart_RstMap::*)(const Standard_Integer &)) &ChFiKPart_RstMap::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_ChFiKPart_RstMap.def("Seek", (const opencascade::handle<Adaptor2d_HCurve2d> * (ChFiKPart_RstMap::*)(const Standard_Integer &) const ) &ChFiKPart_RstMap::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_ChFiKPart_RstMap.def("Find", (const opencascade::handle<Adaptor2d_HCurve2d> & (ChFiKPart_RstMap::*)(const Standard_Integer &) const ) &ChFiKPart_RstMap::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_ChFiKPart_RstMap.def("Find", (Standard_Boolean (ChFiKPart_RstMap::*)(const Standard_Integer &, opencascade::handle<Adaptor2d_HCurve2d> &) const ) &ChFiKPart_RstMap::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_ChFiKPart_RstMap.def("__call__", (const opencascade::handle<Adaptor2d_HCurve2d> & (ChFiKPart_RstMap::*)(const Standard_Integer &) const ) &ChFiKPart_RstMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_ChFiKPart_RstMap.def("ChangeSeek", (opencascade::handle<Adaptor2d_HCurve2d> * (ChFiKPart_RstMap::*)(const Standard_Integer &)) &ChFiKPart_RstMap::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_ChFiKPart_RstMap.def("ChangeFind", (opencascade::handle<Adaptor2d_HCurve2d> & (ChFiKPart_RstMap::*)(const Standard_Integer &)) &ChFiKPart_RstMap::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_ChFiKPart_RstMap.def("__call__", (opencascade::handle<Adaptor2d_HCurve2d> & (ChFiKPart_RstMap::*)(const Standard_Integer &)) &ChFiKPart_RstMap::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_ChFiKPart_RstMap.def("Clear", [](ChFiKPart_RstMap &self) -> void { return self.Clear(); });
	cls_ChFiKPart_RstMap.def("Clear", (void (ChFiKPart_RstMap::*)(const Standard_Boolean)) &ChFiKPart_RstMap::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_ChFiKPart_RstMap.def("Clear", (void (ChFiKPart_RstMap::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &ChFiKPart_RstMap::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_ChFiKPart_RstMap.def("Size", (Standard_Integer (ChFiKPart_RstMap::*)() const ) &ChFiKPart_RstMap::Size, "Size");
	cls_ChFiKPart_RstMap.def("__iter__", [](const ChFiKPart_RstMap &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFiKPart_RstMap.hxx

}
