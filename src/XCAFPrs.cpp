#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <XCAFPrs_Style.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_DataMap.hxx>
#include <XCAFPrs_DataMapOfShapeStyle.hxx>
#include <XCAFPrs_DataMapOfStyleTransient.hxx>
#include <TPrsStd_Driver.hxx>
#include <TDF_Label.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Type.hxx>
#include <XCAFPrs_Driver.hxx>
#include <TopLoc_Location.hxx>
#include <XCAFPrs.hxx>
#include <AIS_ColoredShape.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <XCAFPrs_AISObject.hxx>
#include <XCAFPrs_DataMapOfStyleShape.hxx>

PYBIND11_MODULE(XCAFPrs, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TPrsStd");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.AIS");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Graphic3d");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_Style.hxx
	py::class_<XCAFPrs_Style, std::unique_ptr<XCAFPrs_Style, Deleter<XCAFPrs_Style>>> cls_XCAFPrs_Style(mod, "XCAFPrs_Style", "Represents a set of styling settings applicable to a (sub)shape");
	cls_XCAFPrs_Style.def(py::init<>());
	cls_XCAFPrs_Style.def("IsSetColorSurf", (Standard_Boolean (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::IsSetColorSurf, "Return TRUE if surface color has been defined.");
	cls_XCAFPrs_Style.def("GetColorSurf", (const Quantity_Color & (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::GetColorSurf, "Return surface color.");
	cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
	cls_XCAFPrs_Style.def("GetColorSurfRGBA", (const Quantity_ColorRGBA & (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::GetColorSurfRGBA, "Return surface color.");
	cls_XCAFPrs_Style.def("SetColorSurf", (void (XCAFPrs_Style::*)(const Quantity_ColorRGBA &)) &XCAFPrs_Style::SetColorSurf, "Set surface color.", py::arg("theColor"));
	cls_XCAFPrs_Style.def("UnSetColorSurf", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorSurf, "Manage surface color setting");
	cls_XCAFPrs_Style.def("IsSetColorCurv", (Standard_Boolean (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::IsSetColorCurv, "Return TRUE if curve color has been defined.");
	cls_XCAFPrs_Style.def("GetColorCurv", (const Quantity_Color & (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::GetColorCurv, "Return curve color.");
	cls_XCAFPrs_Style.def("SetColorCurv", (void (XCAFPrs_Style::*)(const Quantity_Color &)) &XCAFPrs_Style::SetColorCurv, "Set curve color.", py::arg("col"));
	cls_XCAFPrs_Style.def("UnSetColorCurv", (void (XCAFPrs_Style::*)()) &XCAFPrs_Style::UnSetColorCurv, "Manage curve color setting");
	cls_XCAFPrs_Style.def("SetVisibility", (void (XCAFPrs_Style::*)(const Standard_Boolean)) &XCAFPrs_Style::SetVisibility, "Assign visibility.", py::arg("theVisibility"));
	cls_XCAFPrs_Style.def("IsVisible", (Standard_Boolean (XCAFPrs_Style::*)() const ) &XCAFPrs_Style::IsVisible, "Manage visibility.");
	cls_XCAFPrs_Style.def("IsEqual", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const ) &XCAFPrs_Style::IsEqual, "Returns True if styles are the same Methods for using Style as key in maps", py::arg("theOther"));
	cls_XCAFPrs_Style.def("__eq__", (Standard_Boolean (XCAFPrs_Style::*)(const XCAFPrs_Style &) const ) &XCAFPrs_Style::operator==, py::is_operator(), "Returns True if styles are the same.", py::arg("theOther"));
	cls_XCAFPrs_Style.def_static("HashCode_", (Standard_Integer (*)(const XCAFPrs_Style &, const Standard_Integer)) &XCAFPrs_Style::HashCode, "Returns a HasCode value.", py::arg("theStyle"), py::arg("theUpper"));
	cls_XCAFPrs_Style.def_static("IsEqual_", (Standard_Boolean (*)(const XCAFPrs_Style &, const XCAFPrs_Style &)) &XCAFPrs_Style::IsEqual, "Returns True when the two keys are the same.", py::arg("theS1"), py::arg("theS2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_Driver.hxx
	py::class_<XCAFPrs_Driver, opencascade::handle<XCAFPrs_Driver>, TPrsStd_Driver> cls_XCAFPrs_Driver(mod, "XCAFPrs_Driver", "Implements a driver for presentation of shapes in DECAF document. Its the only purpose is to initialize and return XCAFPrs_AISObject object on request");
	cls_XCAFPrs_Driver.def("Update", (Standard_Boolean (XCAFPrs_Driver::*)(const TDF_Label &, opencascade::handle<AIS_InteractiveObject> &)) &XCAFPrs_Driver::Update, "None", py::arg("L"), py::arg("ais"));
	cls_XCAFPrs_Driver.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFPrs_Driver::GetID, "returns GUID of the driver");
	cls_XCAFPrs_Driver.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_Driver::get_type_name, "None");
	cls_XCAFPrs_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_Driver::get_type_descriptor, "None");
	cls_XCAFPrs_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_Driver::*)() const ) &XCAFPrs_Driver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs.hxx
	py::class_<XCAFPrs, std::unique_ptr<XCAFPrs, Deleter<XCAFPrs>>> cls_XCAFPrs(mod, "XCAFPrs", "Presentation (visualiation, selection etc.) tools for DECAF documents");
	cls_XCAFPrs.def(py::init<>());
	cls_XCAFPrs.def_static("CollectStyleSettings_", (void (*)(const TDF_Label &, const TopLoc_Location &, XCAFPrs_DataMapOfShapeStyle &)) &XCAFPrs::CollectStyleSettings, "Collect styles defined for shape on label L and its components and subshapes and fills a map of shape - style correspondence The location <loc> is for internal use, it should be Null location for external call", py::arg("L"), py::arg("loc"), py::arg("settings"));
	cls_XCAFPrs.def_static("SetViewNameMode_", (void (*)(const Standard_Boolean)) &XCAFPrs::SetViewNameMode, "Set ViewNameMode for indicate display names or not.", py::arg("viewNameMode"));
	cls_XCAFPrs.def_static("GetViewNameMode_", (Standard_Boolean (*)()) &XCAFPrs::GetViewNameMode, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_AISObject.hxx
	py::class_<XCAFPrs_AISObject, opencascade::handle<XCAFPrs_AISObject>, AIS_ColoredShape> cls_XCAFPrs_AISObject(mod, "XCAFPrs_AISObject", "Implements AIS_InteractiveObject functionality for shape in DECAF document.");
	cls_XCAFPrs_AISObject.def(py::init<const TDF_Label &>(), py::arg("theLabel"));
	cls_XCAFPrs_AISObject.def("GetLabel", (const TDF_Label & (XCAFPrs_AISObject::*)() const ) &XCAFPrs_AISObject::GetLabel, "Returns the label which was visualised by this presentation");
	cls_XCAFPrs_AISObject.def("SetLabel", (void (XCAFPrs_AISObject::*)(const TDF_Label &)) &XCAFPrs_AISObject::SetLabel, "Assign the label to this presentation (but does not mark it outdated with SetToUpdate()).", py::arg("theLabel"));
	cls_XCAFPrs_AISObject.def("DispatchStyles", [](XCAFPrs_AISObject &self) -> void { return self.DispatchStyles(); });
	cls_XCAFPrs_AISObject.def("DispatchStyles", (void (XCAFPrs_AISObject::*)(const Standard_Boolean)) &XCAFPrs_AISObject::DispatchStyles, "Fetch the Shape from associated Label and fill the map of sub-shapes styles. By default, this method is called implicitly within first ::Compute(). Application might call this method explicitly to manipulate styles afterwards.", py::arg("theToSyncStyles"));
	cls_XCAFPrs_AISObject.def("SetMaterial", (void (XCAFPrs_AISObject::*)(const Graphic3d_MaterialAspect &)) &XCAFPrs_AISObject::SetMaterial, "Sets the material aspect. This method assigns the new default material without overriding XDE styles. Re-computation of existing presentation is not required after calling this method.", py::arg("theMaterial"));
	cls_XCAFPrs_AISObject.def_static("get_type_name_", (const char * (*)()) &XCAFPrs_AISObject::get_type_name, "None");
	cls_XCAFPrs_AISObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFPrs_AISObject::get_type_descriptor, "None");
	cls_XCAFPrs_AISObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFPrs_AISObject::*)() const ) &XCAFPrs_AISObject::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XCAFPrs_DataMapOfShapeStyle, std::unique_ptr<XCAFPrs_DataMapOfShapeStyle, Deleter<XCAFPrs_DataMapOfShapeStyle>>, NCollection_BaseMap> cls_XCAFPrs_DataMapOfShapeStyle(mod, "XCAFPrs_DataMapOfShapeStyle", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XCAFPrs_DataMapOfShapeStyle.def(py::init<>());
	cls_XCAFPrs_DataMapOfShapeStyle.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XCAFPrs_DataMapOfShapeStyle.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfShapeStyle.def(py::init([] (const XCAFPrs_DataMapOfShapeStyle &other) {return new XCAFPrs_DataMapOfShapeStyle(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("begin", (XCAFPrs_DataMapOfShapeStyle::iterator (XCAFPrs_DataMapOfShapeStyle::*)() const ) &XCAFPrs_DataMapOfShapeStyle::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfShapeStyle.def("end", (XCAFPrs_DataMapOfShapeStyle::iterator (XCAFPrs_DataMapOfShapeStyle::*)() const ) &XCAFPrs_DataMapOfShapeStyle::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfShapeStyle.def("cbegin", (XCAFPrs_DataMapOfShapeStyle::const_iterator (XCAFPrs_DataMapOfShapeStyle::*)() const ) &XCAFPrs_DataMapOfShapeStyle::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfShapeStyle.def("cend", (XCAFPrs_DataMapOfShapeStyle::const_iterator (XCAFPrs_DataMapOfShapeStyle::*)() const ) &XCAFPrs_DataMapOfShapeStyle::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfShapeStyle.def("Exchange", (void (XCAFPrs_DataMapOfShapeStyle::*)(XCAFPrs_DataMapOfShapeStyle &)) &XCAFPrs_DataMapOfShapeStyle::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("Assign", (XCAFPrs_DataMapOfShapeStyle & (XCAFPrs_DataMapOfShapeStyle::*)(const XCAFPrs_DataMapOfShapeStyle &)) &XCAFPrs_DataMapOfShapeStyle::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("assign", (XCAFPrs_DataMapOfShapeStyle & (XCAFPrs_DataMapOfShapeStyle::*)(const XCAFPrs_DataMapOfShapeStyle &)) &XCAFPrs_DataMapOfShapeStyle::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("ReSize", (void (XCAFPrs_DataMapOfShapeStyle::*)(const Standard_Integer)) &XCAFPrs_DataMapOfShapeStyle::ReSize, "ReSize", py::arg("N"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("Bind", (Standard_Boolean (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &, const XCAFPrs_Style &)) &XCAFPrs_DataMapOfShapeStyle::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XCAFPrs_DataMapOfShapeStyle.def("Bound", (XCAFPrs_Style * (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &, const XCAFPrs_Style &)) &XCAFPrs_DataMapOfShapeStyle::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("IsBound", (Standard_Boolean (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &) const ) &XCAFPrs_DataMapOfShapeStyle::IsBound, "IsBound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("UnBind", (Standard_Boolean (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &)) &XCAFPrs_DataMapOfShapeStyle::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfShapeStyle.def("Seek", (const XCAFPrs_Style * (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &) const ) &XCAFPrs_DataMapOfShapeStyle::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfShapeStyle.def("Find", (const XCAFPrs_Style & (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &) const ) &XCAFPrs_DataMapOfShapeStyle::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfShapeStyle.def("Find", (Standard_Boolean (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &, XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfShapeStyle::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("__call__", (const XCAFPrs_Style & (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &) const ) &XCAFPrs_DataMapOfShapeStyle::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfShapeStyle.def("ChangeSeek", (XCAFPrs_Style * (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &)) &XCAFPrs_DataMapOfShapeStyle::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("ChangeFind", (XCAFPrs_Style & (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &)) &XCAFPrs_DataMapOfShapeStyle::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("__call__", (XCAFPrs_Style & (XCAFPrs_DataMapOfShapeStyle::*)(const TopoDS_Shape &)) &XCAFPrs_DataMapOfShapeStyle::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("Clear", [](XCAFPrs_DataMapOfShapeStyle &self) -> void { return self.Clear(); });
	cls_XCAFPrs_DataMapOfShapeStyle.def("Clear", (void (XCAFPrs_DataMapOfShapeStyle::*)(const Standard_Boolean)) &XCAFPrs_DataMapOfShapeStyle::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("Clear", (void (XCAFPrs_DataMapOfShapeStyle::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFPrs_DataMapOfShapeStyle::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfShapeStyle.def("Size", (Standard_Integer (XCAFPrs_DataMapOfShapeStyle::*)() const ) &XCAFPrs_DataMapOfShapeStyle::Size, "Size");
	cls_XCAFPrs_DataMapOfShapeStyle.def("__iter__", [](const XCAFPrs_DataMapOfShapeStyle &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfShapeStyle.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XCAFPrs_DataMapOfStyleTransient, std::unique_ptr<XCAFPrs_DataMapOfStyleTransient, Deleter<XCAFPrs_DataMapOfStyleTransient>>, NCollection_BaseMap> cls_XCAFPrs_DataMapOfStyleTransient(mod, "XCAFPrs_DataMapOfStyleTransient", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XCAFPrs_DataMapOfStyleTransient.def(py::init<>());
	cls_XCAFPrs_DataMapOfStyleTransient.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XCAFPrs_DataMapOfStyleTransient.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfStyleTransient.def(py::init([] (const XCAFPrs_DataMapOfStyleTransient &other) {return new XCAFPrs_DataMapOfStyleTransient(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("begin", (XCAFPrs_DataMapOfStyleTransient::iterator (XCAFPrs_DataMapOfStyleTransient::*)() const ) &XCAFPrs_DataMapOfStyleTransient::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfStyleTransient.def("end", (XCAFPrs_DataMapOfStyleTransient::iterator (XCAFPrs_DataMapOfStyleTransient::*)() const ) &XCAFPrs_DataMapOfStyleTransient::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfStyleTransient.def("cbegin", (XCAFPrs_DataMapOfStyleTransient::const_iterator (XCAFPrs_DataMapOfStyleTransient::*)() const ) &XCAFPrs_DataMapOfStyleTransient::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfStyleTransient.def("cend", (XCAFPrs_DataMapOfStyleTransient::const_iterator (XCAFPrs_DataMapOfStyleTransient::*)() const ) &XCAFPrs_DataMapOfStyleTransient::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfStyleTransient.def("Exchange", (void (XCAFPrs_DataMapOfStyleTransient::*)(XCAFPrs_DataMapOfStyleTransient &)) &XCAFPrs_DataMapOfStyleTransient::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("Assign", (XCAFPrs_DataMapOfStyleTransient & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_DataMapOfStyleTransient &)) &XCAFPrs_DataMapOfStyleTransient::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("assign", (XCAFPrs_DataMapOfStyleTransient & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_DataMapOfStyleTransient &)) &XCAFPrs_DataMapOfStyleTransient::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("ReSize", (void (XCAFPrs_DataMapOfStyleTransient::*)(const Standard_Integer)) &XCAFPrs_DataMapOfStyleTransient::ReSize, "ReSize", py::arg("N"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("Bind", (Standard_Boolean (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &, const opencascade::handle<Standard_Transient> &)) &XCAFPrs_DataMapOfStyleTransient::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XCAFPrs_DataMapOfStyleTransient.def("Bound", (opencascade::handle<Standard_Transient> * (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &, const opencascade::handle<Standard_Transient> &)) &XCAFPrs_DataMapOfStyleTransient::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("IsBound", (Standard_Boolean (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleTransient::IsBound, "IsBound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("UnBind", (Standard_Boolean (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleTransient::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleTransient.def("Seek", (const opencascade::handle<Standard_Transient> * (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleTransient::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleTransient.def("Find", (const opencascade::handle<Standard_Transient> & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleTransient::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleTransient.def("Find", (Standard_Boolean (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &, opencascade::handle<Standard_Transient> &) const ) &XCAFPrs_DataMapOfStyleTransient::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("__call__", (const opencascade::handle<Standard_Transient> & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleTransient.def("ChangeSeek", (opencascade::handle<Standard_Transient> * (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleTransient::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("ChangeFind", (opencascade::handle<Standard_Transient> & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleTransient::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("__call__", (opencascade::handle<Standard_Transient> & (XCAFPrs_DataMapOfStyleTransient::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleTransient::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("Clear", [](XCAFPrs_DataMapOfStyleTransient &self) -> void { return self.Clear(); });
	cls_XCAFPrs_DataMapOfStyleTransient.def("Clear", (void (XCAFPrs_DataMapOfStyleTransient::*)(const Standard_Boolean)) &XCAFPrs_DataMapOfStyleTransient::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("Clear", (void (XCAFPrs_DataMapOfStyleTransient::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFPrs_DataMapOfStyleTransient::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfStyleTransient.def("Size", (Standard_Integer (XCAFPrs_DataMapOfStyleTransient::*)() const ) &XCAFPrs_DataMapOfStyleTransient::Size, "Size");
	cls_XCAFPrs_DataMapOfStyleTransient.def("__iter__", [](const XCAFPrs_DataMapOfStyleTransient &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfStyleTransient.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<XCAFPrs_DataMapOfStyleShape, std::unique_ptr<XCAFPrs_DataMapOfStyleShape, Deleter<XCAFPrs_DataMapOfStyleShape>>, NCollection_BaseMap> cls_XCAFPrs_DataMapOfStyleShape(mod, "XCAFPrs_DataMapOfStyleShape", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_XCAFPrs_DataMapOfStyleShape.def(py::init<>());
	cls_XCAFPrs_DataMapOfStyleShape.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_XCAFPrs_DataMapOfStyleShape.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfStyleShape.def(py::init([] (const XCAFPrs_DataMapOfStyleShape &other) {return new XCAFPrs_DataMapOfStyleShape(other);}), "Copy constructor", py::arg("other"));
	cls_XCAFPrs_DataMapOfStyleShape.def("begin", (XCAFPrs_DataMapOfStyleShape::iterator (XCAFPrs_DataMapOfStyleShape::*)() const ) &XCAFPrs_DataMapOfStyleShape::begin, "Returns an iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfStyleShape.def("end", (XCAFPrs_DataMapOfStyleShape::iterator (XCAFPrs_DataMapOfStyleShape::*)() const ) &XCAFPrs_DataMapOfStyleShape::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfStyleShape.def("cbegin", (XCAFPrs_DataMapOfStyleShape::const_iterator (XCAFPrs_DataMapOfStyleShape::*)() const ) &XCAFPrs_DataMapOfStyleShape::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_XCAFPrs_DataMapOfStyleShape.def("cend", (XCAFPrs_DataMapOfStyleShape::const_iterator (XCAFPrs_DataMapOfStyleShape::*)() const ) &XCAFPrs_DataMapOfStyleShape::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_XCAFPrs_DataMapOfStyleShape.def("Exchange", (void (XCAFPrs_DataMapOfStyleShape::*)(XCAFPrs_DataMapOfStyleShape &)) &XCAFPrs_DataMapOfStyleShape::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleShape.def("Assign", (XCAFPrs_DataMapOfStyleShape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_DataMapOfStyleShape &)) &XCAFPrs_DataMapOfStyleShape::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleShape.def("assign", (XCAFPrs_DataMapOfStyleShape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_DataMapOfStyleShape &)) &XCAFPrs_DataMapOfStyleShape::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_XCAFPrs_DataMapOfStyleShape.def("ReSize", (void (XCAFPrs_DataMapOfStyleShape::*)(const Standard_Integer)) &XCAFPrs_DataMapOfStyleShape::ReSize, "ReSize", py::arg("N"));
	cls_XCAFPrs_DataMapOfStyleShape.def("Bind", (Standard_Boolean (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &, const TopoDS_Shape &)) &XCAFPrs_DataMapOfStyleShape::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_XCAFPrs_DataMapOfStyleShape.def("Bound", (TopoDS_Shape * (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &, const TopoDS_Shape &)) &XCAFPrs_DataMapOfStyleShape::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_XCAFPrs_DataMapOfStyleShape.def("IsBound", (Standard_Boolean (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleShape::IsBound, "IsBound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleShape.def("UnBind", (Standard_Boolean (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleShape::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleShape.def("Seek", (const TopoDS_Shape * (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleShape::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleShape.def("Find", (const TopoDS_Shape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleShape::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleShape.def("Find", (Standard_Boolean (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &, TopoDS_Shape &) const ) &XCAFPrs_DataMapOfStyleShape::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_XCAFPrs_DataMapOfStyleShape.def("__call__", (const TopoDS_Shape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &) const ) &XCAFPrs_DataMapOfStyleShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_XCAFPrs_DataMapOfStyleShape.def("ChangeSeek", (TopoDS_Shape * (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleShape::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleShape.def("ChangeFind", (TopoDS_Shape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleShape::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleShape.def("__call__", (TopoDS_Shape & (XCAFPrs_DataMapOfStyleShape::*)(const XCAFPrs_Style &)) &XCAFPrs_DataMapOfStyleShape::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_XCAFPrs_DataMapOfStyleShape.def("Clear", [](XCAFPrs_DataMapOfStyleShape &self) -> void { return self.Clear(); });
	cls_XCAFPrs_DataMapOfStyleShape.def("Clear", (void (XCAFPrs_DataMapOfStyleShape::*)(const Standard_Boolean)) &XCAFPrs_DataMapOfStyleShape::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_XCAFPrs_DataMapOfStyleShape.def("Clear", (void (XCAFPrs_DataMapOfStyleShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &XCAFPrs_DataMapOfStyleShape::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_XCAFPrs_DataMapOfStyleShape.def("Size", (Standard_Integer (XCAFPrs_DataMapOfStyleShape::*)() const ) &XCAFPrs_DataMapOfStyleShape::Size, "Size");
	cls_XCAFPrs_DataMapOfStyleShape.def("__iter__", [](const XCAFPrs_DataMapOfStyleShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfStyleShape.hxx

}
