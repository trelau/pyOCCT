#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Prs3d_VertexDrawMode.hxx>
#include <Prs3d_DimensionUnits.hxx>
#include <TCollection_AsciiString.hxx>
#include <Prs3d_TypeOfHLR.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Prs3d_IsoAspect.hxx>
#include <Prs3d_BasicAspect.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <Graphic3d_HorizontalTextAlignment.hxx>
#include <Graphic3d_VerticalTextAlignment.hxx>
#include <Graphic3d_TextPath.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Aspect_TypeOfFacingModel.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Prs3d_PointAspect.hxx>
#include <Prs3d_PlaneAspect.hxx>
#include <Prs3d_ArrowAspect.hxx>
#include <Prs3d_DatumParts.hxx>
#include <Prs3d_DatumAxes.hxx>
#include <Prs3d_DatumAttribute.hxx>
#include <Prs3d_DatumAspect.hxx>
#include <Prs3d_DimensionArrowOrientation.hxx>
#include <Prs3d_DimensionTextVerticalPosition.hxx>
#include <Prs3d_DimensionTextHorizontalPosition.hxx>
#include <Prs3d_DimensionAspect.hxx>
#include <Graphic3d_PresentationAttributes.hxx>
#include <Aspect_TypeOfDeflection.hxx>
#include <Prs3d_Drawer.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Graphic3d_GroupAspect.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_DataStructureManager.hxx>
#include <Geom_Transformation.hxx>
#include <Graphic3d_Group.hxx>
#include <Prs3d_Root.hxx>
#include <Standard_Transient.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Prs3d_Projector.hxx>
#include <Prs3d_TypeOfHighlight.hxx>
#include <Prs3d_DatumMode.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Prs3d.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <gp_Ax1.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <gp_Dir.hxx>
#include <Prs3d_Arrow.hxx>
#include <Standard_RangeError.hxx>
#include <Standard_SStream.hxx>
#include <Prs3d_InvalidAngle.hxx>
#include <Prs3d_NListIteratorOfListOfSequenceOfPnt.hxx>
#include <Graphic3d_ViewAffinity.hxx>
#include <Prs3d_PresentationShadow.hxx>
#include <TopoDS_Face.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopoDS_Vertex.hxx>
#include <Poly_Triangulation.hxx>
#include <TopLoc_Location.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Polygon3D.hxx>
#include <Prs3d_ShapeTool.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Ax2.hxx>
#include <Prs3d_Text.hxx>
#include <gp_Trsf.hxx>
#include <Prs3d_ToolQuadric.hxx>
#include <Prs3d_ToolCylinder.hxx>
#include <Prs3d_ToolDisk.hxx>
#include <Prs3d_ToolSphere.hxx>
#include <Prs3d_TypeOfLinePicking.hxx>

PYBIND11_MODULE(Prs3d, mod) {

	// IMPORT
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.Aspect");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.HLRAlgo");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Poly");
	py::module::import("OCCT.TopLoc");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_VertexDrawMode.hxx
	py::enum_<Prs3d_VertexDrawMode>(mod, "Prs3d_VertexDrawMode", "Describes supported modes of visualization of the shape's vertices: VDM_Isolated - only isolated vertices (not belonging to a face) are displayed. VDM_All - all vertices of the shape are displayed. VDM_Inherited - the global settings are inherited and applied to the shape's presentation.")
		.value("Prs3d_VDM_Isolated", Prs3d_VertexDrawMode::Prs3d_VDM_Isolated)
		.value("Prs3d_VDM_All", Prs3d_VertexDrawMode::Prs3d_VDM_All)
		.value("Prs3d_VDM_Inherited", Prs3d_VertexDrawMode::Prs3d_VDM_Inherited)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_TypeOfHLR.hxx
	py::enum_<Prs3d_TypeOfHLR>(mod, "Prs3d_TypeOfHLR", "Declares types of hidden line removal algorithm. TOH_Algo enables using of exact HLR algorithm. TOH_PolyAlgo enables using of polygonal HLR algorithm. TOH_NotSet is used by Prs3d_Drawer class, it means that the drawer should return the global value. For more details see Prs3d_Drawer class, AIS_Shape::Compute() method and HLRAlgo package from TKHLR toolkit.")
		.value("Prs3d_TOH_NotSet", Prs3d_TypeOfHLR::Prs3d_TOH_NotSet)
		.value("Prs3d_TOH_PolyAlgo", Prs3d_TypeOfHLR::Prs3d_TOH_PolyAlgo)
		.value("Prs3d_TOH_Algo", Prs3d_TypeOfHLR::Prs3d_TOH_Algo)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DimensionArrowOrientation.hxx
	py::enum_<Prs3d_DimensionArrowOrientation>(mod, "Prs3d_DimensionArrowOrientation", "Specifies dimension arrow location and orientation. DAO_Internal - arrows 'inside', pointing outwards. DAO_External - arrows 'outside', pointing inwards. DAO_Fit - arrows oriented inside if value label with arrowtips fit the dimension line, otherwise - externally")
		.value("Prs3d_DAO_Internal", Prs3d_DimensionArrowOrientation::Prs3d_DAO_Internal)
		.value("Prs3d_DAO_External", Prs3d_DimensionArrowOrientation::Prs3d_DAO_External)
		.value("Prs3d_DAO_Fit", Prs3d_DimensionArrowOrientation::Prs3d_DAO_Fit)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DimensionTextHorizontalPosition.hxx
	py::enum_<Prs3d_DimensionTextHorizontalPosition>(mod, "Prs3d_DimensionTextHorizontalPosition", "Specifies options for positioning dimension value label in horizontal direction. DTHP_Left - value label located at left side on dimension extension. DTHP_Right - value label located at right side on dimension extension. DTHP_Center - value label located at center of dimension line. DTHP_Fit - value label located automatically at left side if does not fits the dimension space, otherwise the value label is placed at center.")
		.value("Prs3d_DTHP_Left", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Left)
		.value("Prs3d_DTHP_Right", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Right)
		.value("Prs3d_DTHP_Center", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Center)
		.value("Prs3d_DTHP_Fit", Prs3d_DimensionTextHorizontalPosition::Prs3d_DTHP_Fit)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DimensionTextVerticalPosition.hxx
	py::enum_<Prs3d_DimensionTextVerticalPosition>(mod, "Prs3d_DimensionTextVerticalPosition", "Specifies options for positioning dimension value label in vertical direction with respect to dimension (extension) line. DTVP_Above - text label is located above the dimension or extension line. DTVP_Below - text label is located below the dimension or extension line. DTVP_Center - the text label middle-point is in line with dimension or extension line.")
		.value("Prs3d_DTVP_Above", Prs3d_DimensionTextVerticalPosition::Prs3d_DTVP_Above)
		.value("Prs3d_DTVP_Below", Prs3d_DimensionTextVerticalPosition::Prs3d_DTVP_Below)
		.value("Prs3d_DTVP_Center", Prs3d_DimensionTextVerticalPosition::Prs3d_DTVP_Center)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_TypeOfHighlight.hxx
	py::enum_<Prs3d_TypeOfHighlight>(mod, "Prs3d_TypeOfHighlight", "Type of highlighting to apply specific style.")
		.value("Prs3d_TypeOfHighlight_None", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_None)
		.value("Prs3d_TypeOfHighlight_Selected", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_Selected)
		.value("Prs3d_TypeOfHighlight_Dynamic", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_Dynamic)
		.value("Prs3d_TypeOfHighlight_LocalSelected", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_LocalSelected)
		.value("Prs3d_TypeOfHighlight_LocalDynamic", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_LocalDynamic)
		.value("Prs3d_TypeOfHighlight_SubIntensity", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_SubIntensity)
		.value("Prs3d_TypeOfHighlight_NB", Prs3d_TypeOfHighlight::Prs3d_TypeOfHighlight_NB)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DatumAttribute.hxx
	py::enum_<Prs3d_DatumAttribute>(mod, "Prs3d_DatumAttribute", "Enumeration defining a part of datum aspect, see Prs3d_Datum.")
		.value("Prs3d_DA_XAxisLength", Prs3d_DatumAttribute::Prs3d_DA_XAxisLength)
		.value("Prs3d_DA_YAxisLength", Prs3d_DatumAttribute::Prs3d_DA_YAxisLength)
		.value("Prs3d_DA_ZAxisLength", Prs3d_DatumAttribute::Prs3d_DA_ZAxisLength)
		.value("Prs3d_DP_ShadingTubeRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingTubeRadiusPercent)
		.value("Prs3d_DP_ShadingConeRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingConeRadiusPercent)
		.value("Prs3d_DP_ShadingConeLengthPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingConeLengthPercent)
		.value("Prs3d_DP_ShadingOriginRadiusPercent", Prs3d_DatumAttribute::Prs3d_DP_ShadingOriginRadiusPercent)
		.value("Prs3d_DP_ShadingNumberOfFacettes", Prs3d_DatumAttribute::Prs3d_DP_ShadingNumberOfFacettes)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DatumAxes.hxx
	py::enum_<Prs3d_DatumAxes>(mod, "Prs3d_DatumAxes", "Enumeration defining an axes used in datum aspect, see Prs3d_Datum.")
		.value("Prs3d_DA_XAxis", Prs3d_DatumAxes::Prs3d_DA_XAxis)
		.value("Prs3d_DA_YAxis", Prs3d_DatumAxes::Prs3d_DA_YAxis)
		.value("Prs3d_DA_ZAxis", Prs3d_DatumAxes::Prs3d_DA_ZAxis)
		.value("Prs3d_DA_XYAxis", Prs3d_DatumAxes::Prs3d_DA_XYAxis)
		.value("Prs3d_DA_YZAxis", Prs3d_DatumAxes::Prs3d_DA_YZAxis)
		.value("Prs3d_DA_XZAxis", Prs3d_DatumAxes::Prs3d_DA_XZAxis)
		.value("Prs3d_DA_XYZAxis", Prs3d_DatumAxes::Prs3d_DA_XYZAxis)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DatumMode.hxx
	py::enum_<Prs3d_DatumMode>(mod, "Prs3d_DatumMode", "Enumeration defining a mode of datum graphic presentation, see Prs3d_Datum.")
		.value("Prs3d_DM_WireFrame", Prs3d_DatumMode::Prs3d_DM_WireFrame)
		.value("Prs3d_DM_Shaded", Prs3d_DatumMode::Prs3d_DM_Shaded)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DatumParts.hxx
	py::enum_<Prs3d_DatumParts>(mod, "Prs3d_DatumParts", "Enumeration defining a part of datum aspect, see Prs3d_Datum.")
		.value("Prs3d_DP_Origin", Prs3d_DatumParts::Prs3d_DP_Origin)
		.value("Prs3d_DP_XAxis", Prs3d_DatumParts::Prs3d_DP_XAxis)
		.value("Prs3d_DP_YAxis", Prs3d_DatumParts::Prs3d_DP_YAxis)
		.value("Prs3d_DP_ZAxis", Prs3d_DatumParts::Prs3d_DP_ZAxis)
		.value("Prs3d_DP_XArrow", Prs3d_DatumParts::Prs3d_DP_XArrow)
		.value("Prs3d_DP_YArrow", Prs3d_DatumParts::Prs3d_DP_YArrow)
		.value("Prs3d_DP_ZArrow", Prs3d_DatumParts::Prs3d_DP_ZArrow)
		.value("Prs3d_DP_XOYAxis", Prs3d_DatumParts::Prs3d_DP_XOYAxis)
		.value("Prs3d_DP_YOZAxis", Prs3d_DatumParts::Prs3d_DP_YOZAxis)
		.value("Prs3d_DP_XOZAxis", Prs3d_DatumParts::Prs3d_DP_XOZAxis)
		.value("Prs3d_DP_None", Prs3d_DatumParts::Prs3d_DP_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_TypeOfLinePicking.hxx
	py::enum_<Prs3d_TypeOfLinePicking>(mod, "Prs3d_TypeOfLinePicking", "None")
		.value("Prs3d_TOLP_Point", Prs3d_TypeOfLinePicking::Prs3d_TOLP_Point)
		.value("Prs3d_TOLP_Segment", Prs3d_TypeOfLinePicking::Prs3d_TOLP_Segment)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DimensionUnits.hxx
	py::class_<Prs3d_DimensionUnits, std::unique_ptr<Prs3d_DimensionUnits, Deleter<Prs3d_DimensionUnits>>> cls_Prs3d_DimensionUnits(mod, "Prs3d_DimensionUnits", "This class provides units for two dimension groups: - lengthes (length, radius, diameter) - angles");
	cls_Prs3d_DimensionUnits.def(py::init<>());
	cls_Prs3d_DimensionUnits.def(py::init([] (const Prs3d_DimensionUnits &other) {return new Prs3d_DimensionUnits(other);}), "Copy constructor", py::arg("other"));
	cls_Prs3d_DimensionUnits.def("SetAngleUnits", (void (Prs3d_DimensionUnits::*)(const TCollection_AsciiString &)) &Prs3d_DimensionUnits::SetAngleUnits, "Sets angle units", py::arg("theUnits"));
	cls_Prs3d_DimensionUnits.def("GetAngleUnits", (const TCollection_AsciiString & (Prs3d_DimensionUnits::*)() const ) &Prs3d_DimensionUnits::GetAngleUnits, "Returns angle units");
	cls_Prs3d_DimensionUnits.def("SetLengthUnits", (void (Prs3d_DimensionUnits::*)(const TCollection_AsciiString &)) &Prs3d_DimensionUnits::SetLengthUnits, "Sets length units", py::arg("theUnits"));
	cls_Prs3d_DimensionUnits.def("GetLengthUnits", (const TCollection_AsciiString & (Prs3d_DimensionUnits::*)() const ) &Prs3d_DimensionUnits::GetLengthUnits, "Returns length units");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_BasicAspect.hxx
	py::class_<Prs3d_BasicAspect, opencascade::handle<Prs3d_BasicAspect>, Standard_Transient> cls_Prs3d_BasicAspect(mod, "Prs3d_BasicAspect", "All basic Prs3d_xxxAspect must inherits from this class The aspect classes qualifies how to represent a given kind of object.");
	cls_Prs3d_BasicAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_BasicAspect::get_type_name, "None");
	cls_Prs3d_BasicAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_BasicAspect::get_type_descriptor, "None");
	cls_Prs3d_BasicAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_BasicAspect::*)() const ) &Prs3d_BasicAspect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_LineAspect.hxx
	py::class_<Prs3d_LineAspect, opencascade::handle<Prs3d_LineAspect>, Prs3d_BasicAspect> cls_Prs3d_LineAspect(mod, "Prs3d_LineAspect", "A framework for defining how a line will be displayed in a presentation. Aspects of line display include width, color and type of line. The definition set by this class is then passed to the attribute manager Prs3d_Drawer. Any object which requires a value for line aspect as an argument may then be given the attribute manager as a substitute argument in the form of a field such as myDrawer for example.");
	cls_Prs3d_LineAspect.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));
	cls_Prs3d_LineAspect.def(py::init<const opencascade::handle<Graphic3d_AspectLine3d> &>(), py::arg("theAspect"));
	cls_Prs3d_LineAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_LineAspect::get_type_name, "None");
	cls_Prs3d_LineAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_LineAspect::get_type_descriptor, "None");
	cls_Prs3d_LineAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_LineAspect::*)() const ) &Prs3d_LineAspect::DynamicType, "None");
	cls_Prs3d_LineAspect.def("SetColor", (void (Prs3d_LineAspect::*)(const Quantity_Color &)) &Prs3d_LineAspect::SetColor, "Sets the line color defined at the time of construction. Default value: Quantity_NOC_YELLOW", py::arg("theColor"));
	cls_Prs3d_LineAspect.def("SetTypeOfLine", (void (Prs3d_LineAspect::*)(const Aspect_TypeOfLine)) &Prs3d_LineAspect::SetTypeOfLine, "Sets the type of line defined at the time of construction. This could, for example, be solid, dotted or made up of dashes. Default value: Aspect_TOL_SOLID", py::arg("theType"));
	cls_Prs3d_LineAspect.def("SetWidth", (void (Prs3d_LineAspect::*)(const Standard_Real)) &Prs3d_LineAspect::SetWidth, "Sets the line width defined at the time of construction. Default value: 1.", py::arg("theWidth"));
	cls_Prs3d_LineAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectLine3d> & (Prs3d_LineAspect::*)() const ) &Prs3d_LineAspect::Aspect, "Returns the line aspect. This is defined as the set of color, type and thickness attributes.");
	cls_Prs3d_LineAspect.def("SetAspect", (void (Prs3d_LineAspect::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Prs3d_LineAspect::SetAspect, "None", py::arg("theAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_TextAspect.hxx
	py::class_<Prs3d_TextAspect, opencascade::handle<Prs3d_TextAspect>, Prs3d_BasicAspect> cls_Prs3d_TextAspect(mod, "Prs3d_TextAspect", "Defines the attributes when displaying a text.");
	cls_Prs3d_TextAspect.def(py::init<>());
	cls_Prs3d_TextAspect.def(py::init<const opencascade::handle<Graphic3d_AspectText3d> &>(), py::arg("theAspect"));
	cls_Prs3d_TextAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_TextAspect::get_type_name, "None");
	cls_Prs3d_TextAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_TextAspect::get_type_descriptor, "None");
	cls_Prs3d_TextAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::DynamicType, "None");
	cls_Prs3d_TextAspect.def("SetColor", (void (Prs3d_TextAspect::*)(const Quantity_Color &)) &Prs3d_TextAspect::SetColor, "Sets the color of the type used in text display.", py::arg("theColor"));
	cls_Prs3d_TextAspect.def("SetFont", (void (Prs3d_TextAspect::*)(const Standard_CString)) &Prs3d_TextAspect::SetFont, "Sets the font used in text display.", py::arg("theFont"));
	cls_Prs3d_TextAspect.def("SetHeightWidthRatio", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetHeightWidthRatio, "Returns the height-width ratio, also known as the expansion factor.", py::arg("theRatio"));
	cls_Prs3d_TextAspect.def("SetSpace", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetSpace, "Sets the length of the box which text will occupy.", py::arg("theSpace"));
	cls_Prs3d_TextAspect.def("SetHeight", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetHeight, "Sets the height of the text.", py::arg("theHeight"));
	cls_Prs3d_TextAspect.def("SetAngle", (void (Prs3d_TextAspect::*)(const Standard_Real)) &Prs3d_TextAspect::SetAngle, "Sets the angle", py::arg("theAngle"));
	cls_Prs3d_TextAspect.def("Height", (Standard_Real (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::Height, "Returns the height of the text box.");
	cls_Prs3d_TextAspect.def("Angle", (Standard_Real (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::Angle, "Returns the angle");
	cls_Prs3d_TextAspect.def("SetHorizontalJustification", (void (Prs3d_TextAspect::*)(const Graphic3d_HorizontalTextAlignment)) &Prs3d_TextAspect::SetHorizontalJustification, "Sets horizontal alignment of text.", py::arg("theJustification"));
	cls_Prs3d_TextAspect.def("SetVerticalJustification", (void (Prs3d_TextAspect::*)(const Graphic3d_VerticalTextAlignment)) &Prs3d_TextAspect::SetVerticalJustification, "Sets the vertical alignment of text.", py::arg("theJustification"));
	cls_Prs3d_TextAspect.def("SetOrientation", (void (Prs3d_TextAspect::*)(const Graphic3d_TextPath)) &Prs3d_TextAspect::SetOrientation, "Sets the orientation of text.", py::arg("theOrientation"));
	cls_Prs3d_TextAspect.def("HorizontalJustification", (Graphic3d_HorizontalTextAlignment (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::HorizontalJustification, "Returns the horizontal alignment of the text. The range of values includes: - left - center - right, and - normal (justified).");
	cls_Prs3d_TextAspect.def("VerticalJustification", (Graphic3d_VerticalTextAlignment (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::VerticalJustification, "Returns the vertical alignment of the text. The range of values includes: - normal - top - cap - half - base - bottom");
	cls_Prs3d_TextAspect.def("Orientation", (Graphic3d_TextPath (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::Orientation, "Returns the orientation of the text. Text can be displayed in the following directions: - up - down - left, or - right");
	cls_Prs3d_TextAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectText3d> & (Prs3d_TextAspect::*)() const ) &Prs3d_TextAspect::Aspect, "Returns the purely textual attributes used in the display of text. These include: - color - font - height/width ratio, that is, the expansion factor, and - space between characters.");
	cls_Prs3d_TextAspect.def("SetAspect", (void (Prs3d_TextAspect::*)(const opencascade::handle<Graphic3d_AspectText3d> &)) &Prs3d_TextAspect::SetAspect, "None", py::arg("theAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ShadingAspect.hxx
	py::class_<Prs3d_ShadingAspect, opencascade::handle<Prs3d_ShadingAspect>, Prs3d_BasicAspect> cls_Prs3d_ShadingAspect(mod, "Prs3d_ShadingAspect", "A framework to define the display of shading. The attributes which make up this definition include: - fill aspect - color, and - material");
	cls_Prs3d_ShadingAspect.def(py::init<>());
	cls_Prs3d_ShadingAspect.def(py::init<const opencascade::handle<Graphic3d_AspectFillArea3d> &>(), py::arg("theAspect"));
	cls_Prs3d_ShadingAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_ShadingAspect::get_type_name, "None");
	cls_Prs3d_ShadingAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_ShadingAspect::get_type_descriptor, "None");
	cls_Prs3d_ShadingAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_ShadingAspect::*)() const ) &Prs3d_ShadingAspect::DynamicType, "None");
	cls_Prs3d_ShadingAspect.def("SetColor", [](Prs3d_ShadingAspect &self, const Quantity_Color & a0) -> void { return self.SetColor(a0); }, py::arg("aColor"));
	cls_Prs3d_ShadingAspect.def("SetColor", (void (Prs3d_ShadingAspect::*)(const Quantity_Color &, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetColor, "Change the polygons interior color and material ambient color.", py::arg("aColor"), py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("SetMaterial", [](Prs3d_ShadingAspect &self, const Graphic3d_MaterialAspect & a0) -> void { return self.SetMaterial(a0); }, py::arg("aMaterial"));
	cls_Prs3d_ShadingAspect.def("SetMaterial", (void (Prs3d_ShadingAspect::*)(const Graphic3d_MaterialAspect &, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetMaterial, "Change the polygons material aspect.", py::arg("aMaterial"), py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("SetTransparency", [](Prs3d_ShadingAspect &self, const Standard_Real a0) -> void { return self.SetTransparency(a0); }, py::arg("aValue"));
	cls_Prs3d_ShadingAspect.def("SetTransparency", (void (Prs3d_ShadingAspect::*)(const Standard_Real, const Aspect_TypeOfFacingModel)) &Prs3d_ShadingAspect::SetTransparency, "Change the polygons transparency value. Warning : aValue must be in the range 0,1. 0 is the default (NO transparent)", py::arg("aValue"), py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("Color", [](Prs3d_ShadingAspect &self) -> const Quantity_Color & { return self.Color(); });
	cls_Prs3d_ShadingAspect.def("Color", (const Quantity_Color & (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const ) &Prs3d_ShadingAspect::Color, "Returns the polygons color.", py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("Material", [](Prs3d_ShadingAspect &self) -> const Graphic3d_MaterialAspect & { return self.Material(); });
	cls_Prs3d_ShadingAspect.def("Material", (const Graphic3d_MaterialAspect & (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const ) &Prs3d_ShadingAspect::Material, "Returns the polygons material aspect.", py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("Transparency", [](Prs3d_ShadingAspect &self) -> Standard_Real { return self.Transparency(); });
	cls_Prs3d_ShadingAspect.def("Transparency", (Standard_Real (Prs3d_ShadingAspect::*)(const Aspect_TypeOfFacingModel) const ) &Prs3d_ShadingAspect::Transparency, "Returns the polygons transparency value.", py::arg("aModel"));
	cls_Prs3d_ShadingAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectFillArea3d> & (Prs3d_ShadingAspect::*)() const ) &Prs3d_ShadingAspect::Aspect, "Returns the polygons aspect properties.");
	cls_Prs3d_ShadingAspect.def("SetAspect", (void (Prs3d_ShadingAspect::*)(const opencascade::handle<Graphic3d_AspectFillArea3d> &)) &Prs3d_ShadingAspect::SetAspect, "None", py::arg("theAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_PointAspect.hxx
	py::class_<Prs3d_PointAspect, opencascade::handle<Prs3d_PointAspect>, Prs3d_BasicAspect> cls_Prs3d_PointAspect(mod, "Prs3d_PointAspect", "This class defines attributes for the points The points are drawn using markers, whose size does not depend on the zoom value of the views.");
	cls_Prs3d_PointAspect.def(py::init<const Aspect_TypeOfMarker, const Quantity_Color &, const Standard_Real>(), py::arg("theType"), py::arg("theColor"), py::arg("theScale"));
	cls_Prs3d_PointAspect.def(py::init<const Quantity_Color &, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &>(), py::arg("theColor"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theTexture"));
	cls_Prs3d_PointAspect.def(py::init<const opencascade::handle<Graphic3d_AspectMarker3d> &>(), py::arg("theAspect"));
	cls_Prs3d_PointAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_PointAspect::get_type_name, "None");
	cls_Prs3d_PointAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PointAspect::get_type_descriptor, "None");
	cls_Prs3d_PointAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PointAspect::*)() const ) &Prs3d_PointAspect::DynamicType, "None");
	cls_Prs3d_PointAspect.def("SetColor", (void (Prs3d_PointAspect::*)(const Quantity_Color &)) &Prs3d_PointAspect::SetColor, "defines the color to be used when drawing a point. Default value: Quantity_NOC_YELLOW", py::arg("theColor"));
	cls_Prs3d_PointAspect.def("SetTypeOfMarker", (void (Prs3d_PointAspect::*)(const Aspect_TypeOfMarker)) &Prs3d_PointAspect::SetTypeOfMarker, "defines the type of representation to be used when drawing a point. Default value: Aspect_TOM_PLUS", py::arg("theType"));
	cls_Prs3d_PointAspect.def("SetScale", (void (Prs3d_PointAspect::*)(const Standard_Real)) &Prs3d_PointAspect::SetScale, "defines the size of the marker used when drawing a point. Default value: 1.", py::arg("theScale"));
	cls_Prs3d_PointAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectMarker3d> & (Prs3d_PointAspect::*)() const ) &Prs3d_PointAspect::Aspect, "None");
	cls_Prs3d_PointAspect.def("SetAspect", (void (Prs3d_PointAspect::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &Prs3d_PointAspect::SetAspect, "None", py::arg("theAspect"));
	cls_Prs3d_PointAspect.def("GetTextureSize", (void (Prs3d_PointAspect::*)(Standard_Integer &, Standard_Integer &) const ) &Prs3d_PointAspect::GetTextureSize, "Returns marker's texture size.", py::arg("theWidth"), py::arg("theHeight"));
	cls_Prs3d_PointAspect.def("GetTexture", (const opencascade::handle<Graphic3d_MarkerImage> & (Prs3d_PointAspect::*)() const ) &Prs3d_PointAspect::GetTexture, "Returns marker's texture.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_PlaneAspect.hxx
	py::class_<Prs3d_PlaneAspect, opencascade::handle<Prs3d_PlaneAspect>, Prs3d_BasicAspect> cls_Prs3d_PlaneAspect(mod, "Prs3d_PlaneAspect", "A framework to define the display of planes.");
	cls_Prs3d_PlaneAspect.def(py::init<>());
	cls_Prs3d_PlaneAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_PlaneAspect::get_type_name, "None");
	cls_Prs3d_PlaneAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PlaneAspect::get_type_descriptor, "None");
	cls_Prs3d_PlaneAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::DynamicType, "None");
	cls_Prs3d_PlaneAspect.def("EdgesAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::EdgesAspect, "Returns the attributes of displayed edges involved in the presentation of planes.");
	cls_Prs3d_PlaneAspect.def("IsoAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::IsoAspect, "Returns the attributes of displayed isoparameters involved in the presentation of planes.");
	cls_Prs3d_PlaneAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::ArrowAspect, "Returns the settings for displaying an arrow.");
	cls_Prs3d_PlaneAspect.def("SetArrowsLength", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsLength, "None", py::arg("theLength"));
	cls_Prs3d_PlaneAspect.def("ArrowsLength", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::ArrowsLength, "Returns the length of the arrow shaft used in the display of arrows.");
	cls_Prs3d_PlaneAspect.def("SetArrowsSize", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsSize, "Sets the angle of the arrowhead used in the display of planes.", py::arg("theSize"));
	cls_Prs3d_PlaneAspect.def("ArrowsSize", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::ArrowsSize, "Returns the size of arrows used in the display of planes.");
	cls_Prs3d_PlaneAspect.def("SetArrowsAngle", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsAngle, "Sets the angle of the arrowhead used in the display of arrows involved in the presentation of planes.", py::arg("theAngle"));
	cls_Prs3d_PlaneAspect.def("ArrowsAngle", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::ArrowsAngle, "Returns the angle of the arrowhead used in the display of arrows involved in the presentation of planes.");
	cls_Prs3d_PlaneAspect.def("SetDisplayCenterArrow", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayCenterArrow, "Sets the display attributes defined in DisplayCenterArrow to active.", py::arg("theToDraw"));
	cls_Prs3d_PlaneAspect.def("DisplayCenterArrow", (Standard_Boolean (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::DisplayCenterArrow, "Returns true if the display of center arrows is allowed.");
	cls_Prs3d_PlaneAspect.def("SetDisplayEdgesArrows", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayEdgesArrows, "Sets the display attributes defined in DisplayEdgesArrows to active.", py::arg("theToDraw"));
	cls_Prs3d_PlaneAspect.def("DisplayEdgesArrows", (Standard_Boolean (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::DisplayEdgesArrows, "Returns true if the display of edge arrows is allowed.");
	cls_Prs3d_PlaneAspect.def("SetDisplayEdges", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayEdges, "None", py::arg("theToDraw"));
	cls_Prs3d_PlaneAspect.def("DisplayEdges", (Standard_Boolean (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::DisplayEdges, "None");
	cls_Prs3d_PlaneAspect.def("SetDisplayIso", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayIso, "Sets the display attributes defined in DisplayIso to active.", py::arg("theToDraw"));
	cls_Prs3d_PlaneAspect.def("DisplayIso", (Standard_Boolean (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::DisplayIso, "Returns true if the display of isoparameters is allowed.");
	cls_Prs3d_PlaneAspect.def("SetPlaneLength", (void (Prs3d_PlaneAspect::*)(const Standard_Real, const Standard_Real)) &Prs3d_PlaneAspect::SetPlaneLength, "None", py::arg("theLX"), py::arg("theLY"));
	cls_Prs3d_PlaneAspect.def("PlaneXLength", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::PlaneXLength, "Returns the length of the x axis used in the display of planes.");
	cls_Prs3d_PlaneAspect.def("PlaneYLength", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::PlaneYLength, "Returns the length of the y axis used in the display of planes.");
	cls_Prs3d_PlaneAspect.def("SetIsoDistance", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetIsoDistance, "Sets the distance L between isoparameters used in the display of planes.", py::arg("theL"));
	cls_Prs3d_PlaneAspect.def("IsoDistance", (Standard_Real (Prs3d_PlaneAspect::*)() const ) &Prs3d_PlaneAspect::IsoDistance, "Returns the distance between isoparameters used in the display of planes.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ArrowAspect.hxx
	py::class_<Prs3d_ArrowAspect, opencascade::handle<Prs3d_ArrowAspect>, Prs3d_BasicAspect> cls_Prs3d_ArrowAspect(mod, "Prs3d_ArrowAspect", "A framework for displaying arrows in representations of dimensions and relations.");
	cls_Prs3d_ArrowAspect.def(py::init<>());
	cls_Prs3d_ArrowAspect.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("anAngle"), py::arg("aLength"));
	cls_Prs3d_ArrowAspect.def(py::init<const opencascade::handle<Graphic3d_AspectLine3d> &>(), py::arg("theAspect"));
	cls_Prs3d_ArrowAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_ArrowAspect::get_type_name, "None");
	cls_Prs3d_ArrowAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_ArrowAspect::get_type_descriptor, "None");
	cls_Prs3d_ArrowAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_ArrowAspect::*)() const ) &Prs3d_ArrowAspect::DynamicType, "None");
	cls_Prs3d_ArrowAspect.def("SetAngle", (void (Prs3d_ArrowAspect::*)(const Standard_Real)) &Prs3d_ArrowAspect::SetAngle, "defines the angle of the arrows.", py::arg("anAngle"));
	cls_Prs3d_ArrowAspect.def("Angle", (Standard_Real (Prs3d_ArrowAspect::*)() const ) &Prs3d_ArrowAspect::Angle, "returns the current value of the angle used when drawing an arrow.");
	cls_Prs3d_ArrowAspect.def("SetLength", (void (Prs3d_ArrowAspect::*)(const Standard_Real)) &Prs3d_ArrowAspect::SetLength, "Defines the length of the arrows.", py::arg("theLength"));
	cls_Prs3d_ArrowAspect.def("Length", (Standard_Real (Prs3d_ArrowAspect::*)() const ) &Prs3d_ArrowAspect::Length, "Returns the current value of the length used when drawing an arrow.");
	cls_Prs3d_ArrowAspect.def("SetColor", (void (Prs3d_ArrowAspect::*)(const Quantity_Color &)) &Prs3d_ArrowAspect::SetColor, "None", py::arg("theColor"));
	cls_Prs3d_ArrowAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectLine3d> & (Prs3d_ArrowAspect::*)() const ) &Prs3d_ArrowAspect::Aspect, "None");
	cls_Prs3d_ArrowAspect.def("SetAspect", (void (Prs3d_ArrowAspect::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Prs3d_ArrowAspect::SetAspect, "None", py::arg("theAspect"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DatumAspect.hxx
	py::class_<Prs3d_DatumAspect, opencascade::handle<Prs3d_DatumAspect>, Prs3d_BasicAspect> cls_Prs3d_DatumAspect(mod, "Prs3d_DatumAspect", "A framework to define the display of datums.");
	cls_Prs3d_DatumAspect.def(py::init<>());
	cls_Prs3d_DatumAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_DatumAspect::get_type_name, "None");
	cls_Prs3d_DatumAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_DatumAspect::get_type_descriptor, "None");
	cls_Prs3d_DatumAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::DynamicType, "None");
	cls_Prs3d_DatumAspect.def("LineAspect", (opencascade::handle<Prs3d_LineAspect> (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const ) &Prs3d_DatumAspect::LineAspect, "Returns the right-handed coordinate system set in SetComponent.", py::arg("thePart"));
	cls_Prs3d_DatumAspect.def("ShadingAspect", (opencascade::handle<Prs3d_ShadingAspect> (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const ) &Prs3d_DatumAspect::ShadingAspect, "Returns the right-handed coordinate system set in SetComponent.", py::arg("thePart"));
	cls_Prs3d_DatumAspect.def("TextAspect", (const opencascade::handle<Prs3d_TextAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::TextAspect, "Returns the right-handed coordinate system set in SetComponent.");
	cls_Prs3d_DatumAspect.def("PointAspect", (const opencascade::handle<Prs3d_PointAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::PointAspect, "Returns the point aspect of origin wireframe presentation");
	cls_Prs3d_DatumAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_ArrowAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::ArrowAspect, "Returns the arrow aspect of presentation");
	cls_Prs3d_DatumAspect.def("FirstAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::FirstAxisAspect, "Returns the attributes for display of the first axis.");
	cls_Prs3d_DatumAspect.def("SecondAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::SecondAxisAspect, "Returns the attributes for display of the second axis.");
	cls_Prs3d_DatumAspect.def("ThirdAxisAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::ThirdAxisAspect, "Returns the attributes for display of the third axis.");
	cls_Prs3d_DatumAspect.def("SetDrawFirstAndSecondAxis", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawFirstAndSecondAxis, "Sets the DrawFirstAndSecondAxis attributes to active.", py::arg("theToDraw"));
	cls_Prs3d_DatumAspect.def("DrawFirstAndSecondAxis", (Standard_Boolean (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::DrawFirstAndSecondAxis, "Returns true if the first and second axes can be drawn.");
	cls_Prs3d_DatumAspect.def("SetDrawThirdAxis", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetDrawThirdAxis, "Sets the DrawThirdAxis attributes to active.", py::arg("theToDraw"));
	cls_Prs3d_DatumAspect.def("DrawThirdAxis", (Standard_Boolean (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::DrawThirdAxis, "Returns true if the third axis can be drawn.");
	cls_Prs3d_DatumAspect.def("DrawDatumPart", (Standard_Boolean (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const ) &Prs3d_DatumAspect::DrawDatumPart, "Returns true if the given part is used in axes of aspect", py::arg("thePart"));
	cls_Prs3d_DatumAspect.def("SetDrawDatumAxes", (void (Prs3d_DatumAspect::*)(Prs3d_DatumAxes)) &Prs3d_DatumAspect::SetDrawDatumAxes, "Sets the axes used in the datum aspect", py::arg("theType"));
	cls_Prs3d_DatumAspect.def("DatumAxes", (Prs3d_DatumAxes (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::DatumAxes, "Returns axes used in the datum aspect");
	cls_Prs3d_DatumAspect.def("SetAttribute", (void (Prs3d_DatumAspect::*)(Prs3d_DatumAttribute, const Standard_Real &)) &Prs3d_DatumAspect::SetAttribute, "Sets the attribute of the datum type", py::arg("theType"), py::arg("theValue"));
	cls_Prs3d_DatumAspect.def("Attribute", (Standard_Real (Prs3d_DatumAspect::*)(Prs3d_DatumAttribute) const ) &Prs3d_DatumAspect::Attribute, "Returns the attribute of the datum type", py::arg("theType"));
	cls_Prs3d_DatumAspect.def("SetAxisLength", (void (Prs3d_DatumAspect::*)(Standard_Real, Standard_Real, Standard_Real)) &Prs3d_DatumAspect::SetAxisLength, "Sets the lengths of the three axes.", py::arg("theL1"), py::arg("theL2"), py::arg("theL3"));
	cls_Prs3d_DatumAspect.def("AxisLength", (Standard_Real (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const ) &Prs3d_DatumAspect::AxisLength, "Returns the length of the displayed first axis.", py::arg("thePart"));
	cls_Prs3d_DatumAspect.def("FirstAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::FirstAxisLength, "Returns the length of the displayed first axis.");
	cls_Prs3d_DatumAspect.def("SecondAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::SecondAxisLength, "Returns the length of the displayed second axis.");
	cls_Prs3d_DatumAspect.def("ThirdAxisLength", (Standard_Real (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::ThirdAxisLength, "Returns the length of the displayed third axis.");
	cls_Prs3d_DatumAspect.def("SetToDrawLabels", (void (Prs3d_DatumAspect::*)(Standard_Boolean)) &Prs3d_DatumAspect::SetToDrawLabels, "Sets option to draw or not to draw text labels for axes", py::arg("theToDraw"));
	cls_Prs3d_DatumAspect.def("ToDrawLabels", (Standard_Boolean (Prs3d_DatumAspect::*)() const ) &Prs3d_DatumAspect::ToDrawLabels, "Returns true if axes labels are drawn");
	cls_Prs3d_DatumAspect.def("ArrowPartForAxis", (Prs3d_DatumParts (Prs3d_DatumAspect::*)(Prs3d_DatumParts) const ) &Prs3d_DatumAspect::ArrowPartForAxis, "Returns type of arrow for a type of axis", py::arg("thePart"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_DimensionAspect.hxx
	py::class_<Prs3d_DimensionAspect, opencascade::handle<Prs3d_DimensionAspect>, Prs3d_BasicAspect> cls_Prs3d_DimensionAspect(mod, "Prs3d_DimensionAspect", "defines the attributes when drawing a Length Presentation.");
	cls_Prs3d_DimensionAspect.def(py::init<>());
	cls_Prs3d_DimensionAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_DimensionAspect::get_type_name, "None");
	cls_Prs3d_DimensionAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_DimensionAspect::get_type_descriptor, "None");
	cls_Prs3d_DimensionAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::DynamicType, "None");
	cls_Prs3d_DimensionAspect.def("LineAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::LineAspect, "Returns the settings for the display of lines used in presentation of dimensions.");
	cls_Prs3d_DimensionAspect.def("SetLineAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_DimensionAspect::SetLineAspect, "Sets the display attributes of lines used in presentation of dimensions.", py::arg("theAspect"));
	cls_Prs3d_DimensionAspect.def("TextAspect", (const opencascade::handle<Prs3d_TextAspect> & (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::TextAspect, "Returns the settings for the display of text used in presentation of dimensions.");
	cls_Prs3d_DimensionAspect.def("SetTextAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_TextAspect> &)) &Prs3d_DimensionAspect::SetTextAspect, "Sets the display attributes of text used in presentation of dimensions.", py::arg("theAspect"));
	cls_Prs3d_DimensionAspect.def("IsText3d", (Standard_Boolean (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::IsText3d, "Check if text for dimension label is 3d.");
	cls_Prs3d_DimensionAspect.def("MakeText3d", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeText3d, "Sets type of text.", py::arg("isText3d"));
	cls_Prs3d_DimensionAspect.def("IsTextShaded", (Standard_Boolean (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::IsTextShaded, "Check if 3d text for dimension label is shaded.");
	cls_Prs3d_DimensionAspect.def("MakeTextShaded", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeTextShaded, "Turns on/off text shading for 3d text.", py::arg("theIsTextShaded"));
	cls_Prs3d_DimensionAspect.def("IsArrows3d", (Standard_Boolean (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::IsArrows3d, "Gets type of arrows.");
	cls_Prs3d_DimensionAspect.def("MakeArrows3d", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeArrows3d, "Sets type of arrows.", py::arg("theIsArrows3d"));
	cls_Prs3d_DimensionAspect.def("IsUnitsDisplayed", (Standard_Boolean (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::IsUnitsDisplayed, "Shows if Units are to be displayed along with dimension value.");
	cls_Prs3d_DimensionAspect.def("MakeUnitsDisplayed", (void (Prs3d_DimensionAspect::*)(const Standard_Boolean)) &Prs3d_DimensionAspect::MakeUnitsDisplayed, "Specifies whether the units string should be displayed along with value label or not.", py::arg("theIsDisplayed"));
	cls_Prs3d_DimensionAspect.def("SetArrowOrientation", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionArrowOrientation)) &Prs3d_DimensionAspect::SetArrowOrientation, "Sets orientation of arrows (external or internal). By default orientation is chosen automatically according to situation and text label size.", py::arg("theArrowOrient"));
	cls_Prs3d_DimensionAspect.def("ArrowOrientation", (Prs3d_DimensionArrowOrientation (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::ArrowOrientation, "Gets orientation of arrows (external or internal).");
	cls_Prs3d_DimensionAspect.def("SetTextVerticalPosition", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionTextVerticalPosition)) &Prs3d_DimensionAspect::SetTextVerticalPosition, "Sets vertical text alignment for text label.", py::arg("thePosition"));
	cls_Prs3d_DimensionAspect.def("TextVerticalPosition", (Prs3d_DimensionTextVerticalPosition (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::TextVerticalPosition, "Gets vertical text alignment for text label.");
	cls_Prs3d_DimensionAspect.def("SetTextHorizontalPosition", (void (Prs3d_DimensionAspect::*)(const Prs3d_DimensionTextHorizontalPosition)) &Prs3d_DimensionAspect::SetTextHorizontalPosition, "Sets horizontal text alignment for text label.", py::arg("thePosition"));
	cls_Prs3d_DimensionAspect.def("TextHorizontalPosition", (Prs3d_DimensionTextHorizontalPosition (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::TextHorizontalPosition, "Gets horizontal text alignment for text label.");
	cls_Prs3d_DimensionAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_ArrowAspect> & (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::ArrowAspect, "Returns the settings for displaying arrows.");
	cls_Prs3d_DimensionAspect.def("SetArrowAspect", (void (Prs3d_DimensionAspect::*)(const opencascade::handle<Prs3d_ArrowAspect> &)) &Prs3d_DimensionAspect::SetArrowAspect, "Sets the display attributes of arrows used in presentation of dimensions.", py::arg("theAspect"));
	cls_Prs3d_DimensionAspect.def("SetCommonColor", (void (Prs3d_DimensionAspect::*)(const Quantity_Color &)) &Prs3d_DimensionAspect::SetCommonColor, "Sets the same color for all parts of dimension: lines, arrows and text.", py::arg("theColor"));
	cls_Prs3d_DimensionAspect.def("SetExtensionSize", (void (Prs3d_DimensionAspect::*)(const Standard_Real)) &Prs3d_DimensionAspect::SetExtensionSize, "Sets extension size.", py::arg("theSize"));
	cls_Prs3d_DimensionAspect.def("ExtensionSize", (Standard_Real (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::ExtensionSize, "Returns extension size.");
	cls_Prs3d_DimensionAspect.def("SetArrowTailSize", (void (Prs3d_DimensionAspect::*)(const Standard_Real)) &Prs3d_DimensionAspect::SetArrowTailSize, "Set size for arrow tail (extension without text).", py::arg("theSize"));
	cls_Prs3d_DimensionAspect.def("ArrowTailSize", (Standard_Real (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::ArrowTailSize, "Returns arrow tail size.");
	cls_Prs3d_DimensionAspect.def("SetValueStringFormat", (void (Prs3d_DimensionAspect::*)(const TCollection_AsciiString &)) &Prs3d_DimensionAspect::SetValueStringFormat, "Sets 'sprintf'-syntax format for formatting dimension value labels.", py::arg("theFormat"));
	cls_Prs3d_DimensionAspect.def("ValueStringFormat", (const TCollection_AsciiString & (Prs3d_DimensionAspect::*)() const ) &Prs3d_DimensionAspect::ValueStringFormat, "Returns format.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Drawer.hxx
	py::class_<Prs3d_Drawer, opencascade::handle<Prs3d_Drawer>, Graphic3d_PresentationAttributes> cls_Prs3d_Drawer(mod, "Prs3d_Drawer", "A graphic attribute manager which governs how objects such as color, width, line thickness and deflection are displayed. A drawer includes an instance of the Aspect classes with particular default values.");
	cls_Prs3d_Drawer.def(py::init<>());
	cls_Prs3d_Drawer.def_static("get_type_name_", (const char * (*)()) &Prs3d_Drawer::get_type_name, "None");
	cls_Prs3d_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_Drawer::get_type_descriptor, "None");
	cls_Prs3d_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DynamicType, "None");
	cls_Prs3d_Drawer.def("SetTypeOfDeflection", (void (Prs3d_Drawer::*)(const Aspect_TypeOfDeflection)) &Prs3d_Drawer::SetTypeOfDeflection, "Sets the type of chordal deflection. This indicates whether the deflection value is absolute or relative to the size of the object.", py::arg("theTypeOfDeflection"));
	cls_Prs3d_Drawer.def("TypeOfDeflection", (Aspect_TypeOfDeflection (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::TypeOfDeflection, "Returns the type of chordal deflection. This indicates whether the deflection value is absolute or relative to the size of the object.");
	cls_Prs3d_Drawer.def("HasOwnTypeOfDeflection", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnTypeOfDeflection, "Returns true if the drawer has a type of deflection setting active.");
	cls_Prs3d_Drawer.def("SetMaximalChordialDeviation", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetMaximalChordialDeviation, "Defines the maximal chordial deviation when drawing any curve. Even if the type of deviation is set to TOD_Relative, this value is used by: Prs3d_DeflectionCurve Prs3d_WFDeflectionSurface Prs3d_WFDeflectionRestrictedFace", py::arg("theChordialDeviation"));
	cls_Prs3d_Drawer.def("MaximalChordialDeviation", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::MaximalChordialDeviation, "Returns the maximal chordal deviation. The default value is 0.1. Drawings of curves or patches are made with respect to an absolute maximal chordal deviation.");
	cls_Prs3d_Drawer.def("HasOwnMaximalChordialDeviation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnMaximalChordialDeviation, "Returns true if the drawer has a maximal chordial deviation setting active.");
	cls_Prs3d_Drawer.def("SetTypeOfHLR", (void (Prs3d_Drawer::*)(const Prs3d_TypeOfHLR)) &Prs3d_Drawer::SetTypeOfHLR, "Sets the type of HLR algorithm used by drawer's interactive objects", py::arg("theTypeOfHLR"));
	cls_Prs3d_Drawer.def("TypeOfHLR", (Prs3d_TypeOfHLR (Prs3d_Drawer::*)()) &Prs3d_Drawer::TypeOfHLR, "Returns the type of HLR algorithm currently in use.");
	cls_Prs3d_Drawer.def("HasOwnTypeOfHLR", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnTypeOfHLR, "Returns true if the type of HLR is not equal to Prs3d_TOH_NotSet.");
	cls_Prs3d_Drawer.def("SetMaximalParameterValue", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetMaximalParameterValue, "Defines the maximum value allowed for the first and last parameters of an infinite curve.", py::arg("theValue"));
	cls_Prs3d_Drawer.def("MaximalParameterValue", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::MaximalParameterValue, "Sets the maximum value allowed for the first and last parameters of an infinite curve. By default, this value is 500000.");
	cls_Prs3d_Drawer.def("HasOwnMaximalParameterValue", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnMaximalParameterValue, "Returns true if the drawer has a maximum value allowed for the first and last parameters of an infinite curve setting active.");
	cls_Prs3d_Drawer.def("SetIsoOnPlane", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetIsoOnPlane, "Sets IsoOnPlane on or off by setting the parameter theIsEnabled to true or false.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("IsoOnPlane", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::IsoOnPlane, "Returns True if the drawing of isos on planes is enabled.");
	cls_Prs3d_Drawer.def("HasOwnIsoOnPlane", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnIsoOnPlane, "Returns true if the drawer has IsoOnPlane setting active.");
	cls_Prs3d_Drawer.def("IsoOnTriangulation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::IsoOnTriangulation, "Returns True if the drawing of isos on triangulation is enabled.");
	cls_Prs3d_Drawer.def("HasOwnIsoOnTriangulation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnIsoOnTriangulation, "Returns true if the drawer has IsoOnTriangulation setting active.");
	cls_Prs3d_Drawer.def("SetIsoOnTriangulation", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetIsoOnTriangulation, "Enables or disables isolines on triangulation by setting the parameter theIsEnabled to true or false.", py::arg("theToEnable"));
	cls_Prs3d_Drawer.def("SetDiscretisation", (void (Prs3d_Drawer::*)(const Standard_Integer)) &Prs3d_Drawer::SetDiscretisation, "Sets the discretisation parameter theValue.", py::arg("theValue"));
	cls_Prs3d_Drawer.def("Discretisation", (Standard_Integer (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::Discretisation, "Returns the discretisation setting.");
	cls_Prs3d_Drawer.def("HasOwnDiscretisation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDiscretisation, "Returns true if the drawer has discretisation setting active.");
	cls_Prs3d_Drawer.def("SetDeviationCoefficient", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetDeviationCoefficient, "Sets the deviation coefficient theCoefficient. Also sets the hasOwnDeviationCoefficient flag to Standard_True and myPreviousDeviationCoefficient", py::arg("theCoefficient"));
	cls_Prs3d_Drawer.def("DeviationCoefficient", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DeviationCoefficient, "Returns the deviation coefficient. Drawings of curves or patches are made with respect to a maximal chordal deviation. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient gives the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. This deviation is absolute and is set through the method: SetMaximalChordialDeviation. The default value is 0.001. In drawing shapes, however, you are allowed to ask for a relative deviation. This deviation will be: SizeOfObject * DeviationCoefficient.");
	cls_Prs3d_Drawer.def("SetDeviationCoefficient", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::SetDeviationCoefficient, "Sets the hasOwnDeviationCoefficient flag to Standard_False");
	cls_Prs3d_Drawer.def("HasOwnDeviationCoefficient", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDeviationCoefficient, "Returns true if there is a local setting for deviation coefficient in this framework for a specific interactive object.");
	cls_Prs3d_Drawer.def("PreviousDeviationCoefficient", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::PreviousDeviationCoefficient, "Saves the previous value used for the chordal deviation coefficient.");
	cls_Prs3d_Drawer.def("UpdatePreviousDeviationCoefficient", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::UpdatePreviousDeviationCoefficient, "Updates the previous value used for the chordal deviation coefficient to the current state.");
	cls_Prs3d_Drawer.def("SetHLRDeviationCoefficient", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetHLRDeviationCoefficient, "Sets the deviation coefficient aCoefficient for removal of hidden lines created by different viewpoints in different presentations. The Default value is 0.02. Also sets the hasOwnHLRDeviationCoefficient flag to Standard_True and myPreviousHLRDeviationCoefficient", py::arg("theCoefficient"));
	cls_Prs3d_Drawer.def("HLRDeviationCoefficient", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HLRDeviationCoefficient, "Returns the real number value of the hidden line removal deviation coefficient in this framework, if the flag hasOwnHLRDeviationCoefficient is true or there is no Link. Else the shape's HLR deviation coefficient is used. A Deviation coefficient is used in the shading display mode. The shape is seen decomposed into triangles. These are used to calculate reflection of light from the surface of the object. The triangles are formed from chords of the curves in the shape. The deviation coefficient give the highest value of the angle with which a chord can deviate from a tangent to a curve. If this limit is reached, a new triangle is begun. To find the hidden lines, hidden line display mode entails recalculation of the view at each different projector perspective. Since hidden lines entail calculations of more than usual complexity to decompose them into these triangles, a deviation coefficient allowing greater tolerance is used. This increases efficiency in calculation. The Default value is 0.02.");
	cls_Prs3d_Drawer.def("SetHLRDeviationCoefficient", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::SetHLRDeviationCoefficient, "Sets the hasOwnHLRDeviationCoefficient flag to Standard_False");
	cls_Prs3d_Drawer.def("HasOwnHLRDeviationCoefficient", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnHLRDeviationCoefficient, "Returns true if the there is a setting for HLR deviation coefficient in this framework for a specific interactive object.");
	cls_Prs3d_Drawer.def("PreviousHLRDeviationCoefficient", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::PreviousHLRDeviationCoefficient, "Returns the previous value of the hidden line removal deviation coefficient.");
	cls_Prs3d_Drawer.def("SetDeviationAngle", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetDeviationAngle, "Sets the deviation angle theAngle. Also sets the hasOwnDeviationAngle flag to Standard_True, and myPreviousDeviationAngle.", py::arg("theAngle"));
	cls_Prs3d_Drawer.def("DeviationAngle", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DeviationAngle, "Returns the value for deviation angle.");
	cls_Prs3d_Drawer.def("SetDeviationAngle", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::SetDeviationAngle, "Sets the hasOwnDeviationAngle flag to Standard_False");
	cls_Prs3d_Drawer.def("HasOwnDeviationAngle", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDeviationAngle, "Returns true if the there is a local setting for deviation angle in this framework for a specific interactive object.");
	cls_Prs3d_Drawer.def("PreviousDeviationAngle", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::PreviousDeviationAngle, "Returns the previous deviation angle");
	cls_Prs3d_Drawer.def("UpdatePreviousDeviationAngle", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::UpdatePreviousDeviationAngle, "Updates the previous deviation angle to the current value");
	cls_Prs3d_Drawer.def("SetHLRAngle", (void (Prs3d_Drawer::*)(const Standard_Real)) &Prs3d_Drawer::SetHLRAngle, "Sets anAngle, the angle of maximum chordal deviation for removal of hidden lines created by different viewpoints in different presentations. The default value is 20 * M_PI / 180. Also sets the hasOwnHLRDeviationAngle flag to Standard_True and myPreviousHLRDeviationAngle.", py::arg("theAngle"));
	cls_Prs3d_Drawer.def("HLRAngle", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HLRAngle, "Returns the real number value of the deviation angle in hidden line removal views. The default value is 20 * M_PI / 180.");
	cls_Prs3d_Drawer.def("SetHLRAngle", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::SetHLRAngle, "Sets the hasOwnHLRDeviationAngle flag to Standard_False");
	cls_Prs3d_Drawer.def("HasOwnHLRDeviationAngle", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnHLRDeviationAngle, "Returns true if the there is a setting for HLR deviation angle in this framework for a specific interactive object.");
	cls_Prs3d_Drawer.def("PreviousHLRDeviationAngle", (Standard_Real (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::PreviousHLRDeviationAngle, "Returns the previous value of the HLR deviation angle.");
	cls_Prs3d_Drawer.def("SetAutoTriangulation", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetAutoTriangulation, "Sets IsAutoTriangulated on or off by setting the parameter theIsEnabled to true or false. If this flag is True automatic re-triangulation with deflection-check logic will be applied. Else this feature will be disable and triangulation is expected to be computed by application itself and no shading presentation at all if unavailable.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("IsAutoTriangulation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::IsAutoTriangulation, "Returns True if automatic triangulation is enabled.");
	cls_Prs3d_Drawer.def("HasOwnIsAutoTriangulation", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnIsAutoTriangulation, "Returns true if the drawer has IsoOnPlane setting active.");
	cls_Prs3d_Drawer.def("UIsoAspect", (const opencascade::handle<Prs3d_IsoAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::UIsoAspect, "Defines the attributes which are used when drawing an U isoparametric curve of a face. Defines the number of U isoparametric curves to be drawn for a single face. The LineAspect for U isoparametric lines can be edited (methods SetColor, SetTypeOfLine, SetWidth, SetNumber) The default values are: COLOR : Quantity_NOC_GRAY75 TYPE OF LINE: Aspect_TOL_SOLID WIDTH : 0.5");
	cls_Prs3d_Drawer.def("SetUIsoAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_IsoAspect> &)) &Prs3d_Drawer::SetUIsoAspect, "None", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnUIsoAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnUIsoAspect, "Returns true if the drawer has its own attribute for UIso aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("VIsoAspect", (const opencascade::handle<Prs3d_IsoAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::VIsoAspect, "Defines the attributes which are used when drawing an V isoparametric curve of a face. Defines the number of V isoparametric curves to be drawn for a single face. The LineAspect for V isoparametric lines can be edited (methods SetColor, SetTypeOfLine, SetWidth, SetNumber) The default values are: COLOR : Quantity_NOC_GRAY82 TYPE OF LINE: Aspect_TOL_SOLID WIDTH : 0.5");
	cls_Prs3d_Drawer.def("SetVIsoAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_IsoAspect> &)) &Prs3d_Drawer::SetVIsoAspect, "Sets the appearance of V isoparameters - theAspect.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnVIsoAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnVIsoAspect, "Returns true if the drawer has its own attribute for VIso aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("WireAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::WireAspect, "Returns wire aspect settings. The LineAspect for the free boundaries can be edited. The default values are: Color: Quantity_NOC_GREEN Type of line: Aspect_TOL_SOLID Width: 1.0 These attributes are used by the algorithm Prs3d_WFShape.");
	cls_Prs3d_Drawer.def("SetWireAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetWireAspect, "Sets the parameter theAspect for display of wires.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnWireAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnWireAspect, "Returns true if the drawer has its own attribute for wire aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetWireDraw", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetWireDraw, "Sets WireDraw on or off by setting the parameter theIsEnabled to true or false.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("WireDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::WireDraw, "Returns True if the drawing of the wire is enabled.");
	cls_Prs3d_Drawer.def("HasOwnWireDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnWireDraw, "Returns true if the drawer has its own attribute for 'draw wires' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("PointAspect", (const opencascade::handle<Prs3d_PointAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::PointAspect, "Returns the point aspect setting. The default values are Color: Quantity_NOC_YELLOW Type of marker: Aspect_TOM_PLUS Scale: 1.0 These attributes are used by the algorithms Prs3d_Point.");
	cls_Prs3d_Drawer.def("SetPointAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_PointAspect> &)) &Prs3d_Drawer::SetPointAspect, "Sets the parameter theAspect for display attributes of points", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnPointAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnPointAspect, "Returns true if the drawer has its own attribute for point aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("LineAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::LineAspect, "Returns settings for line aspects. These settings can be edited. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_SOLID Width: 1.0 These attributes are used by the following algorithms: Prs3d_Curve Prs3d_Line Prs3d_HLRShape");
	cls_Prs3d_Drawer.def("SetLineAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetLineAspect, "Sets the parameter theAspect for display attributes of lines.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnLineAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnLineAspect, "Returns true if the drawer has its own attribute for line aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("TextAspect", (const opencascade::handle<Prs3d_TextAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::TextAspect, "Returns settings for text aspect. These settings can be edited. The default value is: - Color: Quantity_NOC_YELLOW");
	cls_Prs3d_Drawer.def("SetTextAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_TextAspect> &)) &Prs3d_Drawer::SetTextAspect, "Sets the parameter theAspect for display attributes of text.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnTextAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnTextAspect, "Returns true if the drawer has its own attribute for text aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("ShadingAspect", (const opencascade::handle<Prs3d_ShadingAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::ShadingAspect, "Returns settings for shading aspects. These settings can be edited. The default values are: - Color: Quantity_NOC_YELLOW - Material: Graphic3d_NOM_BRASS Shading aspect is obtained through decomposition of 3d faces into triangles, each side of each triangle being a chord of the corresponding curved edge in the face. Reflection of light in each projector perspective is then calculated for each of the resultant triangular planes.");
	cls_Prs3d_Drawer.def("SetShadingAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_ShadingAspect> &)) &Prs3d_Drawer::SetShadingAspect, "Sets the parameter theAspect for display attributes of shading.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnShadingAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnShadingAspect, "Returns true if the drawer has its own attribute for shading aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SeenLineAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::SeenLineAspect, "Returns settings for seen line aspects. These settings can be edited. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_SOLID Width: 1.0");
	cls_Prs3d_Drawer.def("SetSeenLineAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetSeenLineAspect, "Sets the parameter theAspect for the display of seen lines in hidden line removal mode.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnSeenLineAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnSeenLineAspect, "Returns true if the drawer has its own attribute for seen line aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("PlaneAspect", (const opencascade::handle<Prs3d_PlaneAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::PlaneAspect, "Returns settings for the appearance of planes.");
	cls_Prs3d_Drawer.def("SetPlaneAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_PlaneAspect> &)) &Prs3d_Drawer::SetPlaneAspect, "Sets the parameter theAspect for the display of planes.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnPlaneAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnPlaneAspect, "Returns true if the drawer has its own attribute for plane aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("ArrowAspect", (const opencascade::handle<Prs3d_ArrowAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::ArrowAspect, "Returns the attributes for display of arrows.");
	cls_Prs3d_Drawer.def("SetArrowAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_ArrowAspect> &)) &Prs3d_Drawer::SetArrowAspect, "Sets the parameter theAspect for display attributes of arrows.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnArrowAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnArrowAspect, "Returns true if the drawer has its own attribute for arrow aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetLineArrowDraw", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetLineArrowDraw, "Enables the drawing of an arrow at the end of each line. By default the arrows are not drawn.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("LineArrowDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::LineArrowDraw, "Returns True if drawing an arrow at the end of each edge is enabled and False otherwise (the default).");
	cls_Prs3d_Drawer.def("HasOwnLineArrowDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnLineArrowDraw, "Returns true if the drawer has its own attribute for 'draw arrow' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("HiddenLineAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::HiddenLineAspect, "Returns settings for hidden line aspects. These settings can be edited. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_DASH Width: 1.0");
	cls_Prs3d_Drawer.def("SetHiddenLineAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetHiddenLineAspect, "Sets the parameter theAspect for the display of hidden lines in hidden line removal mode.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnHiddenLineAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnHiddenLineAspect, "Returns true if the drawer has its own attribute for hidden lines aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("DrawHiddenLine", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DrawHiddenLine, "Returns Standard_True if the hidden lines are to be drawn. By default the hidden lines are not drawn.");
	cls_Prs3d_Drawer.def("EnableDrawHiddenLine", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::EnableDrawHiddenLine, "Enables the DrawHiddenLine function.");
	cls_Prs3d_Drawer.def("DisableDrawHiddenLine", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::DisableDrawHiddenLine, "Disables the DrawHiddenLine function.");
	cls_Prs3d_Drawer.def("HasOwnDrawHiddenLine", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDrawHiddenLine, "Returns true if the drawer has its own attribute for 'draw hidden lines' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("VectorAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::VectorAspect, "Returns settings for the appearance of vectors. These settings can be edited. The default values are: Color: Quantity_NOC_SKYBLUE Type of line: Aspect_TOL_SOLID Width: 1.0");
	cls_Prs3d_Drawer.def("SetVectorAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetVectorAspect, "Sets the modality theAspect for the display of vectors.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnVectorAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnVectorAspect, "Returns true if the drawer has its own attribute for vector aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetVertexDrawMode", (void (Prs3d_Drawer::*)(const Prs3d_VertexDrawMode)) &Prs3d_Drawer::SetVertexDrawMode, "Sets the mode of visualization of vertices of a TopoDS_Shape instance. By default, only stand-alone vertices (not belonging topologically to an edge) are drawn, that corresponds to Prs3d_VDM_Standalone mode. Switching to Prs3d_VDM_Standalone mode makes all shape's vertices visible. To inherit this parameter from the global drawer instance ('the link') when it is present, Prs3d_VDM_Inherited value should be used.", py::arg("theMode"));
	cls_Prs3d_Drawer.def("VertexDrawMode", (Prs3d_VertexDrawMode (Prs3d_Drawer::*)()) &Prs3d_Drawer::VertexDrawMode, "Returns the current mode of visualization of vertices of a TopoDS_Shape instance.");
	cls_Prs3d_Drawer.def("HasOwnVertexDrawMode", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnVertexDrawMode, "Returns true if the vertex draw mode is not equal to Prs3d_VDM_Inherited. This means that individual vertex draw mode value (i.e. not inherited from the global drawer) is used for a specific interactive object.");
	cls_Prs3d_Drawer.def("DatumAspect", (const opencascade::handle<Prs3d_DatumAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::DatumAspect, "Returns settings for the appearance of datums. These settings can be edited. The default values for the three axes are: Color: Quantity_NOC_PEACHPUFF Type of line: Aspect_TOL_SOLID Width: 1.0");
	cls_Prs3d_Drawer.def("SetDatumAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_DatumAspect> &)) &Prs3d_Drawer::SetDatumAspect, "Sets the modality theAspect for the display of datums.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnDatumAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDatumAspect, "Returns true if the drawer has its own attribute for datum aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SectionAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::SectionAspect, "The LineAspect for the wire can be edited. The default values are: Color: Quantity_NOC_ORANGE Type of line: Aspect_TOL_SOLID Width: 1.0 These attributes are used by the algorithm Prs3d_WFShape.");
	cls_Prs3d_Drawer.def("SetSectionAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetSectionAspect, "Sets the parameter theAspect for display attributes of sections.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnSectionAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnSectionAspect, "Returns true if the drawer has its own attribute for section aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetFreeBoundaryAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetFreeBoundaryAspect, "Sets the parameter theAspect for the display of free boundaries. The method sets aspect owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("FreeBoundaryAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::FreeBoundaryAspect, "Returns the values for presentation of free boundaries, in other words, boundaries which are not shared. The LineAspect for the free boundaries can be edited. The default values are: Color: Quantity_NOC_GREEN Type of line: Aspect_TOL_SOLID Width: 1.0 These attributes are used by the algorithm Prs3d_WFShape");
	cls_Prs3d_Drawer.def("HasOwnFreeBoundaryAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnFreeBoundaryAspect, "Returns true if the drawer has its own attribute for free boundaries aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetFreeBoundaryDraw", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetFreeBoundaryDraw, "Enables or disables drawing of free boundaries for shading presentations. The method sets drawing flag owned by the drawer that will be used during visualization instead of the one set in link. theIsEnabled is a boolean flag indicating whether the free boundaries should be drawn or not.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("FreeBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::FreeBoundaryDraw, "Returns True if the drawing of the free boundaries is enabled True is the default setting.");
	cls_Prs3d_Drawer.def("HasOwnFreeBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnFreeBoundaryDraw, "Returns true if the drawer has its own attribute for 'draw free boundaries' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetUnFreeBoundaryAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetUnFreeBoundaryAspect, "Sets the parameter theAspect for the display of shared boundaries. The method sets aspect owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("UnFreeBoundaryAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::UnFreeBoundaryAspect, "Returns settings for shared boundary line aspects. The LineAspect for the unfree boundaries can be edited. The default values are: Color: Quantity_NOC_YELLOW Type of line: Aspect_TOL_SOLID Width: 1. These attributes are used by the algorithm Prs3d_WFShape");
	cls_Prs3d_Drawer.def("HasOwnUnFreeBoundaryAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnUnFreeBoundaryAspect, "Returns true if the drawer has its own attribute for unfree boundaries aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetUnFreeBoundaryDraw", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetUnFreeBoundaryDraw, "Enables or disables drawing of shared boundaries for shading presentations. The method sets drawing flag owned by the drawer that will be used during visualization instead of the one set in link. theIsEnabled is a boolean flag indicating whether the shared boundaries should be drawn or not.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("UnFreeBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::UnFreeBoundaryDraw, "Returns True if the drawing of the shared boundaries is enabled. True is the default setting.");
	cls_Prs3d_Drawer.def("HasOwnUnFreeBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnUnFreeBoundaryDraw, "Returns true if the drawer has its own attribute for 'draw shared boundaries' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetFaceBoundaryAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_LineAspect> &)) &Prs3d_Drawer::SetFaceBoundaryAspect, "Sets line aspect for face boundaries. The method sets line aspect owned by the drawer that will be used during visualization instead of the one set in link. theAspect is the line aspect that determines the look of the face boundaries.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("FaceBoundaryAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::FaceBoundaryAspect, "Returns line aspect of face boundaries.");
	cls_Prs3d_Drawer.def("HasOwnFaceBoundaryAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnFaceBoundaryAspect, "Returns true if the drawer has its own attribute for face boundaries aspect that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetFaceBoundaryDraw", (void (Prs3d_Drawer::*)(const Standard_Boolean)) &Prs3d_Drawer::SetFaceBoundaryDraw, "Enables or disables face boundary drawing for shading presentations. The method sets drawing flag owned by the drawer that will be used during visualization instead of the one set in link. theIsEnabled is a boolean flag indicating whether the face boundaries should be drawn or not.", py::arg("theIsEnabled"));
	cls_Prs3d_Drawer.def("FaceBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::FaceBoundaryDraw, "Checks whether the face boundary drawing is enabled or not.");
	cls_Prs3d_Drawer.def("HasOwnFaceBoundaryDraw", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnFaceBoundaryDraw, "Returns true if the drawer has its own attribute for 'draw face boundaries' flag that overrides the one in the link.");
	cls_Prs3d_Drawer.def("DimensionAspect", (const opencascade::handle<Prs3d_DimensionAspect> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::DimensionAspect, "Returns settings for the appearance of dimensions.");
	cls_Prs3d_Drawer.def("SetDimensionAspect", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_DimensionAspect> &)) &Prs3d_Drawer::SetDimensionAspect, "Sets the settings for the appearance of dimensions. The method sets aspect owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theAspect"));
	cls_Prs3d_Drawer.def("HasOwnDimensionAspect", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDimensionAspect, "Returns true if the drawer has its own attribute for the appearance of dimensions that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetDimLengthModelUnits", (void (Prs3d_Drawer::*)(const TCollection_AsciiString &)) &Prs3d_Drawer::SetDimLengthModelUnits, "Sets dimension length model units for computing of dimension presentation. The method sets value owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theUnits"));
	cls_Prs3d_Drawer.def("SetDimAngleModelUnits", (void (Prs3d_Drawer::*)(const TCollection_AsciiString &)) &Prs3d_Drawer::SetDimAngleModelUnits, "Sets dimension angle model units for computing of dimension presentation. The method sets value owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theUnits"));
	cls_Prs3d_Drawer.def("DimLengthModelUnits", (const TCollection_AsciiString & (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DimLengthModelUnits, "Returns length model units for the dimension presentation.");
	cls_Prs3d_Drawer.def("DimAngleModelUnits", (const TCollection_AsciiString & (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DimAngleModelUnits, "Returns angle model units for the dimension presentation.");
	cls_Prs3d_Drawer.def("HasOwnDimLengthModelUnits", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDimLengthModelUnits, "Returns true if the drawer has its own attribute for dimension length model units that overrides the one in the link.");
	cls_Prs3d_Drawer.def("HasOwnDimAngleModelUnits", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDimAngleModelUnits, "Returns true if the drawer has its own attribute for dimension angle model units that overrides the one in the link.");
	cls_Prs3d_Drawer.def("SetDimLengthDisplayUnits", (void (Prs3d_Drawer::*)(const TCollection_AsciiString &)) &Prs3d_Drawer::SetDimLengthDisplayUnits, "Sets length units in which value for dimension presentation is displayed. The method sets value owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theUnits"));
	cls_Prs3d_Drawer.def("SetDimAngleDisplayUnits", (void (Prs3d_Drawer::*)(const TCollection_AsciiString &)) &Prs3d_Drawer::SetDimAngleDisplayUnits, "Sets angle units in which value for dimension presentation is displayed. The method sets value owned by the drawer that will be used during visualization instead of the one set in link.", py::arg("theUnits"));
	cls_Prs3d_Drawer.def("DimLengthDisplayUnits", (const TCollection_AsciiString & (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DimLengthDisplayUnits, "Returns length units in which dimension presentation is displayed.");
	cls_Prs3d_Drawer.def("DimAngleDisplayUnits", (const TCollection_AsciiString & (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::DimAngleDisplayUnits, "Returns angle units in which dimension presentation is displayed.");
	cls_Prs3d_Drawer.def("HasOwnDimLengthDisplayUnits", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDimLengthDisplayUnits, "Returns true if the drawer has its own attribute for length units in which dimension presentation is displayed that overrides the one in the link.");
	cls_Prs3d_Drawer.def("HasOwnDimAngleDisplayUnits", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasOwnDimAngleDisplayUnits, "Returns true if the drawer has its own attribute for angle units in which dimension presentation is displayed that overrides the one in the link.");
	cls_Prs3d_Drawer.def("Link", (const opencascade::handle<Prs3d_Drawer> & (Prs3d_Drawer::*)()) &Prs3d_Drawer::Link, "Returns the drawer to which the current object references.");
	cls_Prs3d_Drawer.def("HasLink", (Standard_Boolean (Prs3d_Drawer::*)() const ) &Prs3d_Drawer::HasLink, "Returns true if the current object has a link on the other drawer.");
	cls_Prs3d_Drawer.def("Link", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_Drawer> &)) &Prs3d_Drawer::Link, "Sets theDrawer as a link to which the current object references.", py::arg("theDrawer"));
	cls_Prs3d_Drawer.def("SetLink", (void (Prs3d_Drawer::*)(const opencascade::handle<Prs3d_Drawer> &)) &Prs3d_Drawer::SetLink, "Sets theDrawer as a link to which the current object references.", py::arg("theDrawer"));
	cls_Prs3d_Drawer.def("ClearLocalAttributes", (void (Prs3d_Drawer::*)()) &Prs3d_Drawer::ClearLocalAttributes, "Removes local attributes.");
	cls_Prs3d_Drawer.def("SetShaderProgram", [](Prs3d_Drawer &self, const opencascade::handle<Graphic3d_ShaderProgram> & a0, const Graphic3d_GroupAspect a1) -> void { return self.SetShaderProgram(a0, a1); }, py::arg("theProgram"), py::arg("theAspect"));
	cls_Prs3d_Drawer.def("SetShaderProgram", (void (Prs3d_Drawer::*)(const opencascade::handle<Graphic3d_ShaderProgram> &, const Graphic3d_GroupAspect, const bool)) &Prs3d_Drawer::SetShaderProgram, "Assign shader program for specified type of primitives.", py::arg("theProgram"), py::arg("theAspect"), py::arg("theToOverrideDefaults"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Presentation.hxx
	py::class_<Prs3d_Presentation, opencascade::handle<Prs3d_Presentation>, Graphic3d_Structure> cls_Prs3d_Presentation(mod, "Prs3d_Presentation", "Defines a presentation object which can be displayed, highlighted or erased. The presentation object stores the results of the presentation algorithms as defined in the StdPrs classes and the Prs3d classes inheriting Prs3d_Root. This presentation object is used to give display attributes defined at this level to ApplicationInteractiveServices classes at the level above. A presentation object is attached to a given Viewer.");
	cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("theStructManager"));
	cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const Standard_Boolean>(), py::arg("theStructManager"), py::arg("theToInit"));
	cls_Prs3d_Presentation.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Prs3d_Presentation> &>(), py::arg("theStructManager"), py::arg("thePrs"));
	cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &)) &Prs3d_Presentation::Compute, "None", py::arg("aProjector"));
	cls_Prs3d_Presentation.def("Compute", (opencascade::handle<Graphic3d_Structure> (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"));
	cls_Prs3d_Presentation.def("Compute", (void (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, opencascade::handle<Graphic3d_Structure> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("aProjector"), py::arg("aStructure"));
	cls_Prs3d_Presentation.def("Compute", (void (Prs3d_Presentation::*)(const opencascade::handle<Graphic3d_DataStructureManager> &, const opencascade::handle<Geom_Transformation> &, opencascade::handle<Graphic3d_Structure> &)) &Prs3d_Presentation::Compute, "Returns the new Structure defined for the new visualization", py::arg("theProjector"), py::arg("theTrsf"), py::arg("theStructure"));
	cls_Prs3d_Presentation.def("Connect", (void (Prs3d_Presentation::*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Presentation::Connect, "None", py::arg("aPresentation"));
	cls_Prs3d_Presentation.def("Remove", (void (Prs3d_Presentation::*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Presentation::Remove, "None", py::arg("aPresentation"));
	cls_Prs3d_Presentation.def("RemoveAll", (void (Prs3d_Presentation::*)()) &Prs3d_Presentation::RemoveAll, "None");
	cls_Prs3d_Presentation.def_static("get_type_name_", (const char * (*)()) &Prs3d_Presentation::get_type_name, "None");
	cls_Prs3d_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_Presentation::get_type_descriptor, "None");
	cls_Prs3d_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_Presentation::*)() const ) &Prs3d_Presentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Root.hxx
	py::class_<Prs3d_Root, std::unique_ptr<Prs3d_Root, Deleter<Prs3d_Root>>> cls_Prs3d_Root(mod, "Prs3d_Root", "A root class for the standard presentation algorithms of the StdPrs package.");
	cls_Prs3d_Root.def(py::init<>());
	cls_Prs3d_Root.def_static("CurrentGroup_", (opencascade::handle<Graphic3d_Group> (*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Root::CurrentGroup, "Returns the current (last created) group of primititves inside graphic objects in the display. A group also contains the attributes whose ranges are limited to the primitives in it.", py::arg("thePrs3d"));
	cls_Prs3d_Root.def_static("NewGroup_", (opencascade::handle<Graphic3d_Group> (*)(const opencascade::handle<Prs3d_Presentation> &)) &Prs3d_Root::NewGroup, "Returns the new group of primitives inside graphic objects in the display. A group also contains the attributes whose ranges are limited to the primitives in it.", py::arg("thePrs3d"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Projector.hxx
	py::class_<Prs3d_Projector, opencascade::handle<Prs3d_Projector>, Standard_Transient> cls_Prs3d_Projector(mod, "Prs3d_Projector", "A projector object. This object defines the parameters of a view for a visualization algorithm. It is, for example, used by the hidden line removal algorithms.");
	cls_Prs3d_Projector.def(py::init<const HLRAlgo_Projector &>(), py::arg("Pr"));
	cls_Prs3d_Projector.def(py::init<const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Pers"), py::arg("Focus"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("XAt"), py::arg("YAt"), py::arg("ZAt"), py::arg("XUp"), py::arg("YUp"), py::arg("ZUp"));
	cls_Prs3d_Projector.def("Projector", (HLRAlgo_Projector (Prs3d_Projector::*)() const ) &Prs3d_Projector::Projector, "Returns a projector object for use in a hidden line removal algorithm.");
	cls_Prs3d_Projector.def_static("get_type_name_", (const char * (*)()) &Prs3d_Projector::get_type_name, "None");
	cls_Prs3d_Projector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_Projector::get_type_descriptor, "None");
	cls_Prs3d_Projector.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_Projector::*)() const ) &Prs3d_Projector::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_IsoAspect.hxx
	py::class_<Prs3d_IsoAspect, opencascade::handle<Prs3d_IsoAspect>, Prs3d_LineAspect> cls_Prs3d_IsoAspect(mod, "Prs3d_IsoAspect", "A framework to define the display attributes of isoparameters. This framework can be used to modify the default setting for isoparameters in Prs3d_Drawer.");
	cls_Prs3d_IsoAspect.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Standard_Integer>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"), py::arg("theNumber"));
	cls_Prs3d_IsoAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_IsoAspect::get_type_name, "None");
	cls_Prs3d_IsoAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_IsoAspect::get_type_descriptor, "None");
	cls_Prs3d_IsoAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_IsoAspect::*)() const ) &Prs3d_IsoAspect::DynamicType, "None");
	cls_Prs3d_IsoAspect.def("SetNumber", (void (Prs3d_IsoAspect::*)(const Standard_Integer)) &Prs3d_IsoAspect::SetNumber, "defines the number of U or V isoparametric curves to be drawn for a single face. Default value: 10", py::arg("theNumber"));
	cls_Prs3d_IsoAspect.def("Number", (Standard_Integer (Prs3d_IsoAspect::*)() const ) &Prs3d_IsoAspect::Number, "returns the number of U or V isoparametric curves drawn for a single face.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d.hxx
	py::class_<Prs3d, std::unique_ptr<Prs3d, Deleter<Prs3d>>> cls_Prs3d(mod, "Prs3d", "The Prs3d package provides the following services - a presentation object (the context for all modifications to the display, its presentation will be displayed in every view of an active viewer) - an attribute manager governing how objects such as color, width, and type of line are displayed; these are generic objects, whereas those in StdPrs are specific geometries and topologies. - generic algorithms providing default settings for objects such as points, curves, surfaces and shapes - a root object which provides the abstract framework for the DsgPrs definitions at work in display of dimensions, relations and trihedra.");
	cls_Prs3d.def(py::init<>());
	cls_Prs3d.def_static("MatchSegment_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &, const gp_Pnt &, Standard_Real &)) &Prs3d::MatchSegment, "draws an arrow at a given location, with respect to a given direction.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("p1"), py::arg("p2"), py::arg("dist"));
	cls_Prs3d.def_static("GetDeflection_", (Standard_Real (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &Prs3d::GetDeflection, "Computes the absolute deflection value depending on the type of deflection in theDrawer: Aspect_TOD_RELATIVE: the absolute deflection is computed using the relative deviation coefficient from theDrawer and the shape's bounding box; Aspect_TOD_ABSOLUTE: the maximal chordial deviation from theDrawer is returned. In case of the type of deflection in theDrawer computed relative deflection for shape is stored as absolute deflection. It is necessary to use it later on for sub-shapes. This function should always be used to compute the deflection value for building discrete representations of the shape (triangualtion, wireframe) to avoid incosistencies between different representations of the shape and undesirable visual artifacts.", py::arg("theShape"), py::arg("theDrawer"));
	cls_Prs3d.def_static("PrimitivesFromPolylines_", (opencascade::handle<Graphic3d_ArrayOfPrimitives> (*)(const Prs3d_NListOfSequenceOfPnt &)) &Prs3d::PrimitivesFromPolylines, "Assembles array of primitives for sequence of polylines.", py::arg("thePoints"));
	cls_Prs3d.def_static("AddPrimitivesGroup_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_LineAspect> &, Prs3d_NListOfSequenceOfPnt &)) &Prs3d::AddPrimitivesGroup, "Add primitives into new group in presentation and clear the list of polylines.", py::arg("thePrs"), py::arg("theAspect"), py::arg("thePolylines"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Arrow.hxx
	py::class_<Prs3d_Arrow, std::unique_ptr<Prs3d_Arrow, Deleter<Prs3d_Arrow>>, Prs3d_Root> cls_Prs3d_Arrow(mod, "Prs3d_Arrow", "Provides class methods to draw an arrow at a given location, along a given direction and using a given angle.");
	cls_Prs3d_Arrow.def(py::init<>());
	cls_Prs3d_Arrow.def_static("DrawShaded_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const gp_Ax1 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer)) &Prs3d_Arrow::DrawShaded, "Defines the representation of the arrow as shaded triangulation.", py::arg("theAxis"), py::arg("theTubeRadius"), py::arg("theAxisLength"), py::arg("theConeRadius"), py::arg("theConeLength"), py::arg("theNbFacettes"));
	cls_Prs3d_Arrow.def_static("DrawSegments_", (opencascade::handle<Graphic3d_ArrayOfSegments> (*)(const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real, const Standard_Integer)) &Prs3d_Arrow::DrawSegments, "Defines the representation of the arrow as a container of segments.", py::arg("theLocation"), py::arg("theDir"), py::arg("theAngle"), py::arg("theLength"), py::arg("theNbSegments"));
	cls_Prs3d_Arrow.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real)) &Prs3d_Arrow::Draw, "Defines the representation of the arrow. Note that this method does NOT assign any presentation aspects to the primitives group!", py::arg("theGroup"), py::arg("theLocation"), py::arg("theDirection"), py::arg("theAngle"), py::arg("theLength"));
	cls_Prs3d_Arrow.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const gp_Pnt &, const gp_Dir &, const Standard_Real, const Standard_Real)) &Prs3d_Arrow::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theLocation"), py::arg("theDirection"), py::arg("theAngle"), py::arg("theLength"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_InvalidAngle.hxx
	py::class_<Prs3d_InvalidAngle, opencascade::handle<Prs3d_InvalidAngle>, Standard_RangeError> cls_Prs3d_InvalidAngle(mod, "Prs3d_InvalidAngle", "None");
	cls_Prs3d_InvalidAngle.def(py::init<>());
	cls_Prs3d_InvalidAngle.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_Prs3d_InvalidAngle.def_static("Raise_", (void (*)(const Standard_CString)) &Prs3d_InvalidAngle::Raise, "None", py::arg("theMessage"));
	cls_Prs3d_InvalidAngle.def_static("Raise_", (void (*)(Standard_SStream &)) &Prs3d_InvalidAngle::Raise, "None", py::arg("theMessage"));
	cls_Prs3d_InvalidAngle.def_static("NewInstance_", (opencascade::handle<Prs3d_InvalidAngle> (*)(const Standard_CString)) &Prs3d_InvalidAngle::NewInstance, "None", py::arg("theMessage"));
	cls_Prs3d_InvalidAngle.def_static("get_type_name_", (const char * (*)()) &Prs3d_InvalidAngle::get_type_name, "None");
	cls_Prs3d_InvalidAngle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_InvalidAngle::get_type_descriptor, "None");
	cls_Prs3d_InvalidAngle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_InvalidAngle::*)() const ) &Prs3d_InvalidAngle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_PresentationShadow.hxx
	py::class_<Prs3d_PresentationShadow, opencascade::handle<Prs3d_PresentationShadow>, Prs3d_Presentation> cls_Prs3d_PresentationShadow(mod, "Prs3d_PresentationShadow", "Defines a 'shadow' of existing presentation object with custom aspects.");
	cls_Prs3d_PresentationShadow.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<Prs3d_Presentation> &>(), py::arg("theViewer"), py::arg("thePrs"));
	cls_Prs3d_PresentationShadow.def("ParentId", (Standard_Integer (Prs3d_PresentationShadow::*)() const ) &Prs3d_PresentationShadow::ParentId, "Returns the id of the parent presentation");
	cls_Prs3d_PresentationShadow.def("ParentAffinity", (const opencascade::handle<Graphic3d_ViewAffinity> & (Prs3d_PresentationShadow::*)() const ) &Prs3d_PresentationShadow::ParentAffinity, "Returns view affinity of the parent presentation");
	cls_Prs3d_PresentationShadow.def("CalculateBoundBox", (void (Prs3d_PresentationShadow::*)()) &Prs3d_PresentationShadow::CalculateBoundBox, "Do nothing - axis-aligned bounding box should be initialized from parent structure.");
	cls_Prs3d_PresentationShadow.def_static("get_type_name_", (const char * (*)()) &Prs3d_PresentationShadow::get_type_name, "None");
	cls_Prs3d_PresentationShadow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PresentationShadow::get_type_descriptor, "None");
	cls_Prs3d_PresentationShadow.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PresentationShadow::*)() const ) &Prs3d_PresentationShadow::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ShapeTool.hxx
	py::class_<Prs3d_ShapeTool, std::unique_ptr<Prs3d_ShapeTool, Deleter<Prs3d_ShapeTool>>> cls_Prs3d_ShapeTool(mod, "Prs3d_ShapeTool", "describes the behaviour requested for a wireframe shape presentation.");
	cls_Prs3d_ShapeTool.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));
	cls_Prs3d_ShapeTool.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theShape"), py::arg("theAllVertices"));
	cls_Prs3d_ShapeTool.def("InitFace", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitFace, "None");
	cls_Prs3d_ShapeTool.def("MoreFace", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::MoreFace, "None");
	cls_Prs3d_ShapeTool.def("NextFace", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextFace, "None");
	cls_Prs3d_ShapeTool.def("GetFace", (const TopoDS_Face & (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::GetFace, "None");
	cls_Prs3d_ShapeTool.def("FaceBound", (Bnd_Box (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::FaceBound, "None");
	cls_Prs3d_ShapeTool.def("IsPlanarFace", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::IsPlanarFace, "None");
	cls_Prs3d_ShapeTool.def("InitCurve", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitCurve, "None");
	cls_Prs3d_ShapeTool.def("MoreCurve", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::MoreCurve, "None");
	cls_Prs3d_ShapeTool.def("NextCurve", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextCurve, "None");
	cls_Prs3d_ShapeTool.def("GetCurve", (const TopoDS_Edge & (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::GetCurve, "None");
	cls_Prs3d_ShapeTool.def("CurveBound", (Bnd_Box (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::CurveBound, "None");
	cls_Prs3d_ShapeTool.def("Neighbours", (Standard_Integer (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::Neighbours, "None");
	cls_Prs3d_ShapeTool.def("FacesOfEdge", (opencascade::handle<TopTools_HSequenceOfShape> (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::FacesOfEdge, "None");
	cls_Prs3d_ShapeTool.def("InitVertex", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::InitVertex, "None");
	cls_Prs3d_ShapeTool.def("MoreVertex", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::MoreVertex, "None");
	cls_Prs3d_ShapeTool.def("NextVertex", (void (Prs3d_ShapeTool::*)()) &Prs3d_ShapeTool::NextVertex, "None");
	cls_Prs3d_ShapeTool.def("GetVertex", (const TopoDS_Vertex & (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::GetVertex, "None");
	cls_Prs3d_ShapeTool.def("HasSurface", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::HasSurface, "None");
	cls_Prs3d_ShapeTool.def("CurrentTriangulation", (opencascade::handle<Poly_Triangulation> (Prs3d_ShapeTool::*)(TopLoc_Location &) const ) &Prs3d_ShapeTool::CurrentTriangulation, "None", py::arg("l"));
	cls_Prs3d_ShapeTool.def("HasCurve", (Standard_Boolean (Prs3d_ShapeTool::*)() const ) &Prs3d_ShapeTool::HasCurve, "None");
	cls_Prs3d_ShapeTool.def("PolygonOnTriangulation", (void (Prs3d_ShapeTool::*)(opencascade::handle<Poly_PolygonOnTriangulation> &, opencascade::handle<Poly_Triangulation> &, TopLoc_Location &) const ) &Prs3d_ShapeTool::PolygonOnTriangulation, "None", py::arg("Indices"), py::arg("T"), py::arg("l"));
	cls_Prs3d_ShapeTool.def("Polygon3D", (opencascade::handle<Poly_Polygon3D> (Prs3d_ShapeTool::*)(TopLoc_Location &) const ) &Prs3d_ShapeTool::Polygon3D, "None", py::arg("l"));
	cls_Prs3d_ShapeTool.def_static("IsPlanarFace_", (Standard_Boolean (*)(const TopoDS_Face &)) &Prs3d_ShapeTool::IsPlanarFace, "None", py::arg("theFace"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Text.hxx
	py::class_<Prs3d_Text, std::unique_ptr<Prs3d_Text, Deleter<Prs3d_Text>>, Prs3d_Root> cls_Prs3d_Text(mod, "Prs3d_Text", "A framework to define the display of texts.");
	cls_Prs3d_Text.def(py::init<>());
	cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Defines the display of the text.", py::arg("theGroup"), py::arg("theAspect"), py::arg("theText"), py::arg("theAttachmentPoint"));
	cls_Prs3d_Text.def_static("Draw_", [](const opencascade::handle<Graphic3d_Group> & a0, const opencascade::handle<Prs3d_TextAspect> & a1, const TCollection_ExtendedString & a2, const gp_Ax2 & a3) -> void { return Prs3d_Text::Draw(a0, a1, a2, a3); }, py::arg("theGroup"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"));
	cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Boolean)) &Prs3d_Text::Draw, "Draws the text label.", py::arg("theGroup"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"), py::arg("theHasOwnAnchor"));
	cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theDrawer"), py::arg("theText"), py::arg("theAttachmentPoint"));
	cls_Prs3d_Text.def_static("Draw_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_TextAspect> & a1, const TCollection_ExtendedString & a2, const gp_Ax2 & a3) -> void { return Prs3d_Text::Draw(a0, a1, a2, a3); }, py::arg("thePrs"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"));
	cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Boolean)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"), py::arg("theHasOwnAnchor"));
	cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theAspect"), py::arg("theText"), py::arg("theAttachmentPoint"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ToolQuadric.hxx
	py::class_<Prs3d_ToolQuadric, std::unique_ptr<Prs3d_ToolQuadric, Deleter<Prs3d_ToolQuadric>>> cls_Prs3d_ToolQuadric(mod, "Prs3d_ToolQuadric", "Base class to build 3D surfaces presentation of quadric surfaces.");
	cls_Prs3d_ToolQuadric.def("FillArray", (void (Prs3d_ToolQuadric::*)(opencascade::handle<Graphic3d_ArrayOfTriangles> &, const gp_Trsf &)) &Prs3d_ToolQuadric::FillArray, "Generate primitives for 3D quadric surface and fill the given array. Optional transformation is applied.", py::arg("theArray"), py::arg("theTrsf"));
	cls_Prs3d_ToolQuadric.def("FillArray", (void (Prs3d_ToolQuadric::*)(opencascade::handle<Graphic3d_ArrayOfTriangles> &, opencascade::handle<Poly_Triangulation> &, const gp_Trsf &)) &Prs3d_ToolQuadric::FillArray, "Generate primitives for 3D quadric surface presentation and fill the given array and poly triangulation structure. Optional transformation is applied.", py::arg("theArray"), py::arg("theTriangulation"), py::arg("theTrsf"));
	cls_Prs3d_ToolQuadric.def_static("TrianglesNb_", (Standard_Integer (*)(const Standard_Integer, const Standard_Integer)) &Prs3d_ToolQuadric::TrianglesNb, "Number of triangles for presentation with the given params.", py::arg("theSlicesNb"), py::arg("theStacksNb"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ToolCylinder.hxx
	py::class_<Prs3d_ToolCylinder, std::unique_ptr<Prs3d_ToolCylinder, Deleter<Prs3d_ToolCylinder>>, Prs3d_ToolQuadric> cls_Prs3d_ToolCylinder(mod, "Prs3d_ToolCylinder", "Standard presentation algorithm that outputs graphical primitives for cylindrical surface.");
	cls_Prs3d_ToolCylinder.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theBottomRad"), py::arg("theTopRad"), py::arg("theHeight"), py::arg("theNbSlices"), py::arg("theNbStacks"));
	cls_Prs3d_ToolCylinder.def_static("Create_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_Trsf &)) &Prs3d_ToolCylinder::Create, "Generate primitives for 3D quadric surface and return a filled array.", py::arg("theBottomRad"), py::arg("theTopRad"), py::arg("theHeight"), py::arg("theNbSlices"), py::arg("theNbStacks"), py::arg("theTrsf"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ToolDisk.hxx
	py::class_<Prs3d_ToolDisk, std::unique_ptr<Prs3d_ToolDisk, Deleter<Prs3d_ToolDisk>>, Prs3d_ToolQuadric> cls_Prs3d_ToolDisk(mod, "Prs3d_ToolDisk", "Standard presentation algorithm that outputs graphical primitives for disk surface.");
	cls_Prs3d_ToolDisk.def(py::init<const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theInnerRadius"), py::arg("theOuterRadius"), py::arg("theNbSlices"), py::arg("theNbStacks"));
	cls_Prs3d_ToolDisk.def_static("Create_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_Trsf &)) &Prs3d_ToolDisk::Create, "Generate primitives for 3D quadric surface and return a filled array.", py::arg("theInnerRadius"), py::arg("theOuterRadius"), py::arg("theNbSlices"), py::arg("theNbStacks"), py::arg("theTrsf"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_ToolSphere.hxx
	py::class_<Prs3d_ToolSphere, std::unique_ptr<Prs3d_ToolSphere, Deleter<Prs3d_ToolSphere>>, Prs3d_ToolQuadric> cls_Prs3d_ToolSphere(mod, "Prs3d_ToolSphere", "Standard presentation algorithm that outputs graphical primitives for spherical surface.");
	cls_Prs3d_ToolSphere.def(py::init<const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("theRadius"), py::arg("theNbSlices"), py::arg("theNbStacks"));
	cls_Prs3d_ToolSphere.def_static("Create_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_Trsf &)) &Prs3d_ToolSphere::Create, "Generate primitives for 3D quadric surface and return a filled array.", py::arg("theRadius"), py::arg("theNbSlices"), py::arg("theNbStacks"), py::arg("theTrsf"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Prs3d_Drawer.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<Prs3d_NListOfSequenceOfPnt, std::unique_ptr<Prs3d_NListOfSequenceOfPnt, Deleter<Prs3d_NListOfSequenceOfPnt>>, NCollection_BaseList> cls_Prs3d_NListOfSequenceOfPnt(mod, "Prs3d_NListOfSequenceOfPnt", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_Prs3d_NListOfSequenceOfPnt.def(py::init<>());
	cls_Prs3d_NListOfSequenceOfPnt.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Prs3d_NListOfSequenceOfPnt.def(py::init([] (const Prs3d_NListOfSequenceOfPnt &other) {return new Prs3d_NListOfSequenceOfPnt(other);}), "Copy constructor", py::arg("other"));
	cls_Prs3d_NListOfSequenceOfPnt.def("begin", (Prs3d_NListOfSequenceOfPnt::iterator (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::begin, "Returns an iterator pointing to the first element in the list.");
	cls_Prs3d_NListOfSequenceOfPnt.def("end", (Prs3d_NListOfSequenceOfPnt::iterator (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_Prs3d_NListOfSequenceOfPnt.def("cbegin", (Prs3d_NListOfSequenceOfPnt::const_iterator (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_Prs3d_NListOfSequenceOfPnt.def("cend", (Prs3d_NListOfSequenceOfPnt::const_iterator (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_Prs3d_NListOfSequenceOfPnt.def("Size", (Standard_Integer (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::Size, "Size - Number of items");
	cls_Prs3d_NListOfSequenceOfPnt.def("Assign", (Prs3d_NListOfSequenceOfPnt & (Prs3d_NListOfSequenceOfPnt::*)(const Prs3d_NListOfSequenceOfPnt &)) &Prs3d_NListOfSequenceOfPnt::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_Prs3d_NListOfSequenceOfPnt.def("assign", (Prs3d_NListOfSequenceOfPnt & (Prs3d_NListOfSequenceOfPnt::*)(const Prs3d_NListOfSequenceOfPnt &)) &Prs3d_NListOfSequenceOfPnt::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Clear", [](Prs3d_NListOfSequenceOfPnt &self) -> void { return self.Clear(); });
	cls_Prs3d_NListOfSequenceOfPnt.def("Clear", (void (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Prs3d_NListOfSequenceOfPnt::Clear, "Clear this list", py::arg("theAllocator"));
	cls_Prs3d_NListOfSequenceOfPnt.def("First", (const opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::First, "First item");
	cls_Prs3d_NListOfSequenceOfPnt.def("First", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)()) &Prs3d_NListOfSequenceOfPnt::First, "First item (non-const)");
	cls_Prs3d_NListOfSequenceOfPnt.def("Last", (const opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)() const ) &Prs3d_NListOfSequenceOfPnt::Last, "Last item");
	cls_Prs3d_NListOfSequenceOfPnt.def("Last", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)()) &Prs3d_NListOfSequenceOfPnt::Last, "Last item (non-const)");
	cls_Prs3d_NListOfSequenceOfPnt.def("Append", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &)) &Prs3d_NListOfSequenceOfPnt::Append, "Append one item at the end", py::arg("theItem"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Append", (void (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &, Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Append", (void (Prs3d_NListOfSequenceOfPnt::*)(Prs3d_NListOfSequenceOfPnt &)) &Prs3d_NListOfSequenceOfPnt::Append, "Append another list at the end", py::arg("theOther"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Prepend", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &)) &Prs3d_NListOfSequenceOfPnt::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Prepend", (void (Prs3d_NListOfSequenceOfPnt::*)(Prs3d_NListOfSequenceOfPnt &)) &Prs3d_NListOfSequenceOfPnt::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_Prs3d_NListOfSequenceOfPnt.def("RemoveFirst", (void (Prs3d_NListOfSequenceOfPnt::*)()) &Prs3d_NListOfSequenceOfPnt::RemoveFirst, "RemoveFirst item");
	cls_Prs3d_NListOfSequenceOfPnt.def("Remove", (void (Prs3d_NListOfSequenceOfPnt::*)(Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("InsertBefore", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &, Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("InsertBefore", (void (Prs3d_NListOfSequenceOfPnt::*)(Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("InsertAfter", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListOfSequenceOfPnt::*)(const opencascade::handle<TColgp_HSequenceOfPnt> &, Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("InsertAfter", (void (Prs3d_NListOfSequenceOfPnt::*)(Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt::Iterator &)) &Prs3d_NListOfSequenceOfPnt::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_Prs3d_NListOfSequenceOfPnt.def("Reverse", (void (Prs3d_NListOfSequenceOfPnt::*)()) &Prs3d_NListOfSequenceOfPnt::Reverse, "Reverse the list");
	cls_Prs3d_NListOfSequenceOfPnt.def("__iter__", [](const Prs3d_NListOfSequenceOfPnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<Prs3d_NListIteratorOfListOfSequenceOfPnt, std::unique_ptr<Prs3d_NListIteratorOfListOfSequenceOfPnt, Deleter<Prs3d_NListIteratorOfListOfSequenceOfPnt>>> cls_Prs3d_NListIteratorOfListOfSequenceOfPnt(mod, "Prs3d_NListIteratorOfListOfSequenceOfPnt", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def(py::init<>());
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def("More", (Standard_Boolean (Prs3d_NListIteratorOfListOfSequenceOfPnt::*)() const ) &Prs3d_NListIteratorOfListOfSequenceOfPnt::More, "Check end");
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def("Next", (void (Prs3d_NListIteratorOfListOfSequenceOfPnt::*)()) &Prs3d_NListIteratorOfListOfSequenceOfPnt::Next, "Make step");
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def("Value", (const opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListIteratorOfListOfSequenceOfPnt::*)() const ) &Prs3d_NListIteratorOfListOfSequenceOfPnt::Value, "Constant Value access");
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def("Value", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListIteratorOfListOfSequenceOfPnt::*)()) &Prs3d_NListIteratorOfListOfSequenceOfPnt::Value, "Non-const Value access");
	cls_Prs3d_NListIteratorOfListOfSequenceOfPnt.def("ChangeValue", (opencascade::handle<TColgp_HSequenceOfPnt> & (Prs3d_NListIteratorOfListOfSequenceOfPnt::*)() const ) &Prs3d_NListIteratorOfListOfSequenceOfPnt::ChangeValue, "Non-const Value access");


}
