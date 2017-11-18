#include <pyOCCT_Common.hpp>

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
#include <NCollection_Templates.hpp>

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfShapeStyle.hxx
	bind_NCollection_DataMap<TopoDS_Shape, XCAFPrs_Style, TopTools_ShapeMapHasher>(mod, "XCAFPrs_DataMapOfShapeStyle");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfStyleTransient.hxx
	bind_NCollection_DataMap<XCAFPrs_Style, opencascade::handle<Standard_Transient>, XCAFPrs_Style>(mod, "XCAFPrs_DataMapOfStyleTransient");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFPrs_DataMapOfStyleShape.hxx
	bind_NCollection_DataMap<XCAFPrs_Style, TopoDS_Shape, XCAFPrs_Style>(mod, "XCAFPrs_DataMapOfStyleShape");

	/* FIXME

	*/


}
