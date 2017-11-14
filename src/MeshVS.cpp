#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <MeshVS_Array1OfSequenceOfInteger.hxx>
#include <MeshVS_Buffer.hxx>
#include <MeshVS_BuilderPriority.hxx>
#include <MeshVS_SelectionModeFlags.hxx>
#include <MeshVS_ColorHasher.hxx>
#include <MeshVS_EntityType.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <AIS_InteractiveObject.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <Prs3d_Drawer.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <MeshVS_PrsBuilder.hxx>
#include <MeshVS_DataMapOfIntegerOwner.hxx>
#include <MeshVS_DataSource.hxx>
#include <MeshVS_Drawer.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <MeshVS_MeshSelectionMethod.hxx>
#include <MeshVS_Mesh.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Bnd_Box.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Bnd_Box2d.hxx>
#include <MeshVS_MeshPtr.hxx>
#include <MeshVS_DisplayModeFlags.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <TCollection_AsciiString.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <MeshVS_SequenceOfPrsBuilder.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <Select3D_SensitiveSet.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_Pnt.hxx>
#include <MeshVS_CommonSensitiveEntity.hxx>
#include <MeshVS_DataMapOfColorMapOfInteger.hxx>
#include <MeshVS_DataMapOfHArray1OfSequenceOfInteger.hxx>
#include <MeshVS_DataMapOfIntegerAsciiString.hxx>
#include <MeshVS_DataMapOfIntegerBoolean.hxx>
#include <MeshVS_DataMapOfIntegerColor.hxx>
#include <MeshVS_DataMapOfIntegerMaterial.hxx>
#include <SelectMgr_SOPtr.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <MeshVS_MeshEntityOwner.hxx>
#include <MeshVS_DataMapOfIntegerMeshEntityOwner.hxx>
#include <MeshVS_TwoColors.hxx>
#include <MeshVS_TwoNodes.hxx>
#include <MeshVS_DataMapOfIntegerTwoColors.hxx>
#include <MeshVS_DataMapOfIntegerVector.hxx>
#include <MeshVS_TwoColorsHasher.hxx>
#include <MeshVS_DataMapOfTwoColorsMapOfInteger.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <gp_Vec.hxx>
#include <MeshVS_DeformedDataSource.hxx>
#include <MeshVS_DrawerAttribute.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <gp_GTrsf.hxx>
#include <MeshVS_DummySensitiveEntity.hxx>
#include <MeshVS_ElementalColorPrsBuilder.hxx>
#include <MeshVS_TwoNodesHasher.hxx>
#include <NCollection_Map.hxx>
#include <MeshVS_MapOfTwoNodes.hxx>
#include <MeshVS_MeshOwner.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <MeshVS_MeshPrsBuilder.hxx>
#include <Aspect_SequenceOfColor.hxx>
#include <TColStd_DataMapOfIntegerReal.hxx>
#include <MeshVS_NodalColorPrsBuilder.hxx>
#include <Select3D_SensitiveFace.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <MeshVS_SensitiveFace.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <MeshVS_SensitiveMesh.hxx>
#include <MeshVS_SensitivePolyhedron.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <MeshVS_SensitiveQuad.hxx>
#include <Select3D_SensitiveSegment.hxx>
#include <MeshVS_SensitiveSegment.hxx>
#include <MeshVS_SymmetricPairHasher.hxx>
#include <MeshVS_TextPrsBuilder.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_AspectLine3d.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Graphic3d_AspectText3d.hxx>
#include <MeshVS_Tool.hxx>
#include <gp_Trsf.hxx>
#include <MeshVS_VectorPrsBuilder.hxx>

PYBIND11_MODULE(MeshVS, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.AIS");
	py::module::import("OCCT.PrsMgr");
	py::module::import("OCCT.Prs3d");
	py::module::import("OCCT.SelectMgr");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Quantity");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.SelectBasics");
	py::module::import("OCCT.Select3D");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Aspect");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SelectionModeFlags.hxx
	mod.attr("MeshVS_SMF_Mesh") = py::cast(int(MeshVS_SMF_Mesh));
	mod.attr("MeshVS_SMF_Node") = py::cast(int(MeshVS_SMF_Node));
	mod.attr("MeshVS_SMF_0D") = py::cast(int(MeshVS_SMF_0D));
	mod.attr("MeshVS_SMF_Link") = py::cast(int(MeshVS_SMF_Link));
	mod.attr("MeshVS_SMF_Face") = py::cast(int(MeshVS_SMF_Face));
	mod.attr("MeshVS_SMF_Volume") = py::cast(int(MeshVS_SMF_Volume));
	mod.attr("MeshVS_SMF_Element") = py::cast(int(MeshVS_SMF_Element));
	mod.attr("MeshVS_SMF_All") = py::cast(int(MeshVS_SMF_All));
	mod.attr("MeshVS_SMF_Group") = py::cast(int(MeshVS_SMF_Group));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MeshSelectionMethod.hxx
	py::enum_<MeshVS_MeshSelectionMethod>(mod, "MeshVS_MeshSelectionMethod", "this enumeration describe what type of sensitive entity will be built in 0-th selection mode (it means that whole mesh is selected )")
		.value("MeshVS_MSM_PRECISE", MeshVS_MeshSelectionMethod::MeshVS_MSM_PRECISE)
		.value("MeshVS_MSM_NODES", MeshVS_MeshSelectionMethod::MeshVS_MSM_NODES)
		.value("MeshVS_MSM_BOX", MeshVS_MeshSelectionMethod::MeshVS_MSM_BOX)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DrawerAttribute.hxx
	py::enum_<MeshVS_DrawerAttribute>(mod, "MeshVS_DrawerAttribute", "Is it allowed to draw beam and face's edge overlapping with this beam.//! Is mesh drawn with reflective material//! Is colored mesh data representation drawn with reflective material//! What part of face or link will be shown if shrink mode. It is recommended this coeff to be between 0 and 1.//! How many nodes is possible to be in face//! If this parameter is true, the compute method CPU time will be displayed in console window//! If this parameter is true, the compute selection method CPU time will be displayed in console window//! If this parameter is false, the nodes won't be shown in viewer, otherwise will be.//! If this parameter is true, the selectable nodes map will be updated automatically when hidden elements change//! If this parameter is false, the face's edges are not shown Warning: in wireframe mode this parameter is ignored//! Is mesh drawing in smooth shading mode//! Is back faces of volume elements should be supressed//! The integer keys for most useful constants attuning mesh presentation appearence WARNING: DA_TextExpansionFactor, DA_TextSpace, DA_TextDisplayType have no effect and might be removed in the future.")
		.value("MeshVS_DA_InteriorStyle", MeshVS_DrawerAttribute::MeshVS_DA_InteriorStyle)
		.value("MeshVS_DA_InteriorColor", MeshVS_DrawerAttribute::MeshVS_DA_InteriorColor)
		.value("MeshVS_DA_BackInteriorColor", MeshVS_DrawerAttribute::MeshVS_DA_BackInteriorColor)
		.value("MeshVS_DA_EdgeColor", MeshVS_DrawerAttribute::MeshVS_DA_EdgeColor)
		.value("MeshVS_DA_EdgeType", MeshVS_DrawerAttribute::MeshVS_DA_EdgeType)
		.value("MeshVS_DA_EdgeWidth", MeshVS_DrawerAttribute::MeshVS_DA_EdgeWidth)
		.value("MeshVS_DA_HatchStyle", MeshVS_DrawerAttribute::MeshVS_DA_HatchStyle)
		.value("MeshVS_DA_FrontMaterial", MeshVS_DrawerAttribute::MeshVS_DA_FrontMaterial)
		.value("MeshVS_DA_BackMaterial", MeshVS_DrawerAttribute::MeshVS_DA_BackMaterial)
		.value("MeshVS_DA_BeamType", MeshVS_DrawerAttribute::MeshVS_DA_BeamType)
		.value("MeshVS_DA_BeamWidth", MeshVS_DrawerAttribute::MeshVS_DA_BeamWidth)
		.value("MeshVS_DA_BeamColor", MeshVS_DrawerAttribute::MeshVS_DA_BeamColor)
		.value("MeshVS_DA_MarkerType", MeshVS_DrawerAttribute::MeshVS_DA_MarkerType)
		.value("MeshVS_DA_MarkerColor", MeshVS_DrawerAttribute::MeshVS_DA_MarkerColor)
		.value("MeshVS_DA_MarkerScale", MeshVS_DrawerAttribute::MeshVS_DA_MarkerScale)
		.value("MeshVS_DA_TextColor", MeshVS_DrawerAttribute::MeshVS_DA_TextColor)
		.value("MeshVS_DA_TextHeight", MeshVS_DrawerAttribute::MeshVS_DA_TextHeight)
		.value("MeshVS_DA_TextFont", MeshVS_DrawerAttribute::MeshVS_DA_TextFont)
		.value("MeshVS_DA_TextExpansionFactor", MeshVS_DrawerAttribute::MeshVS_DA_TextExpansionFactor)
		.value("MeshVS_DA_TextSpace", MeshVS_DrawerAttribute::MeshVS_DA_TextSpace)
		.value("MeshVS_DA_TextStyle", MeshVS_DrawerAttribute::MeshVS_DA_TextStyle)
		.value("MeshVS_DA_TextDisplayType", MeshVS_DrawerAttribute::MeshVS_DA_TextDisplayType)
		.value("MeshVS_DA_TextTexFont", MeshVS_DrawerAttribute::MeshVS_DA_TextTexFont)
		.value("MeshVS_DA_TextFontAspect", MeshVS_DrawerAttribute::MeshVS_DA_TextFontAspect)
		.value("MeshVS_DA_VectorColor", MeshVS_DrawerAttribute::MeshVS_DA_VectorColor)
		.value("MeshVS_DA_VectorMaxLength", MeshVS_DrawerAttribute::MeshVS_DA_VectorMaxLength)
		.value("MeshVS_DA_VectorArrowPart", MeshVS_DrawerAttribute::MeshVS_DA_VectorArrowPart)
		.value("MeshVS_DA_IsAllowOverlapped", MeshVS_DrawerAttribute::MeshVS_DA_IsAllowOverlapped)
		.value("MeshVS_DA_Reflection", MeshVS_DrawerAttribute::MeshVS_DA_Reflection)
		.value("MeshVS_DA_ColorReflection", MeshVS_DrawerAttribute::MeshVS_DA_ColorReflection)
		.value("MeshVS_DA_ShrinkCoeff", MeshVS_DrawerAttribute::MeshVS_DA_ShrinkCoeff)
		.value("MeshVS_DA_MaxFaceNodes", MeshVS_DrawerAttribute::MeshVS_DA_MaxFaceNodes)
		.value("MeshVS_DA_ComputeTime", MeshVS_DrawerAttribute::MeshVS_DA_ComputeTime)
		.value("MeshVS_DA_ComputeSelectionTime", MeshVS_DrawerAttribute::MeshVS_DA_ComputeSelectionTime)
		.value("MeshVS_DA_DisplayNodes", MeshVS_DrawerAttribute::MeshVS_DA_DisplayNodes)
		.value("MeshVS_DA_SelectableAuto", MeshVS_DrawerAttribute::MeshVS_DA_SelectableAuto)
		.value("MeshVS_DA_ShowEdges", MeshVS_DrawerAttribute::MeshVS_DA_ShowEdges)
		.value("MeshVS_DA_SmoothShading", MeshVS_DrawerAttribute::MeshVS_DA_SmoothShading)
		.value("MeshVS_DA_SupressBackFaces", MeshVS_DrawerAttribute::MeshVS_DA_SupressBackFaces)
		.value("MeshVS_DA_User", MeshVS_DrawerAttribute::MeshVS_DA_User)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoNodes.hxx
	mod.def("HashCode", (Standard_Integer (*)(const MeshVS_TwoNodes &, const Standard_Integer)) &HashCode, "None", py::arg("obj"), py::arg("Upper"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoColors.hxx
	mod.def("IsEqual", (Standard_Boolean (*)(const MeshVS_TwoColors &, const MeshVS_TwoColors &)) &IsEqual, "None", py::arg("K1"), py::arg("K2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoNodes.hxx
	mod.def("__eq__", (Standard_Boolean (*)(const MeshVS_TwoNodes &, const MeshVS_TwoNodes &)) &operator==, py::is_operator(), "None", py::arg("obj1"), py::arg("obj2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoColors.hxx
	mod.def("BindTwoColors", (MeshVS_TwoColors (*)(const Quantity_Color &, const Quantity_Color &)) &BindTwoColors, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoColors.hxx
	mod.def("ExtractColor", (Quantity_Color (*)(MeshVS_TwoColors &, const Standard_Integer)) &ExtractColor, "None", py::arg(""), py::arg(""));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoColors.hxx
	mod.def("ExtractColors", (void (*)(MeshVS_TwoColors &, Quantity_Color &, Quantity_Color &)) &ExtractColors, "None", py::arg(""), py::arg(""), py::arg(""));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_Buffer.hxx
	py::class_<MeshVS_Buffer, std::unique_ptr<MeshVS_Buffer, Deleter<MeshVS_Buffer>>> cls_MeshVS_Buffer(mod, "MeshVS_Buffer", "None");
	cls_MeshVS_Buffer.def(py::init<const Standard_Size>(), py::arg("theSize"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<MeshVS_Array1OfSequenceOfInteger, std::unique_ptr<MeshVS_Array1OfSequenceOfInteger, Deleter<MeshVS_Array1OfSequenceOfInteger>>> cls_MeshVS_Array1OfSequenceOfInteger(mod, "MeshVS_Array1OfSequenceOfInteger", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_MeshVS_Array1OfSequenceOfInteger.def(py::init<>());
	cls_MeshVS_Array1OfSequenceOfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_MeshVS_Array1OfSequenceOfInteger.def(py::init([] (const MeshVS_Array1OfSequenceOfInteger &other) {return new MeshVS_Array1OfSequenceOfInteger(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_MeshVS_Array1OfSequenceOfInteger.def(py::init<MeshVS_Array1OfSequenceOfInteger &&>(), py::arg("theOther"));
	cls_MeshVS_Array1OfSequenceOfInteger.def(py::init<const TColStd_SequenceOfInteger &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("begin", (MeshVS_Array1OfSequenceOfInteger::iterator (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::begin, "Returns an iterator pointing to the first element in the array.");
	cls_MeshVS_Array1OfSequenceOfInteger.def("end", (MeshVS_Array1OfSequenceOfInteger::iterator (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_MeshVS_Array1OfSequenceOfInteger.def("cbegin", (MeshVS_Array1OfSequenceOfInteger::const_iterator (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_MeshVS_Array1OfSequenceOfInteger.def("cend", (MeshVS_Array1OfSequenceOfInteger::const_iterator (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Init", (void (MeshVS_Array1OfSequenceOfInteger::*)(const TColStd_SequenceOfInteger &)) &MeshVS_Array1OfSequenceOfInteger::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("Size", (Standard_Integer (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::Size, "Size query");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Length", (Standard_Integer (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::Length, "Length query (the same)");
	cls_MeshVS_Array1OfSequenceOfInteger.def("IsEmpty", (Standard_Boolean (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::IsEmpty, "Return TRUE if array has zero length.");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Lower", (Standard_Integer (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::Lower, "Lower bound");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Upper", (Standard_Integer (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::Upper, "Upper bound");
	cls_MeshVS_Array1OfSequenceOfInteger.def("IsDeletable", (Standard_Boolean (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::IsDeletable, "myDeletable flag");
	cls_MeshVS_Array1OfSequenceOfInteger.def("IsAllocated", (Standard_Boolean (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Assign", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const MeshVS_Array1OfSequenceOfInteger &)) &MeshVS_Array1OfSequenceOfInteger::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_MeshVS_Array1OfSequenceOfInteger.def("Move", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(MeshVS_Array1OfSequenceOfInteger &&)) &MeshVS_Array1OfSequenceOfInteger::Move, "Move assignment", py::arg("theOther"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("assign", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const MeshVS_Array1OfSequenceOfInteger &)) &MeshVS_Array1OfSequenceOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_MeshVS_Array1OfSequenceOfInteger.def("assign", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(MeshVS_Array1OfSequenceOfInteger &&)) &MeshVS_Array1OfSequenceOfInteger::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("First", (const TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::First, "Returns first element");
	cls_MeshVS_Array1OfSequenceOfInteger.def("ChangeFirst", (TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)()) &MeshVS_Array1OfSequenceOfInteger::ChangeFirst, "Returns first element");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Last", (const TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)() const ) &MeshVS_Array1OfSequenceOfInteger::Last, "Returns last element");
	cls_MeshVS_Array1OfSequenceOfInteger.def("ChangeLast", (TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)()) &MeshVS_Array1OfSequenceOfInteger::ChangeLast, "Returns last element");
	cls_MeshVS_Array1OfSequenceOfInteger.def("Value", (const TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer) const ) &MeshVS_Array1OfSequenceOfInteger::Value, "Constant value access", py::arg("theIndex"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("__call__", (const TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer) const ) &MeshVS_Array1OfSequenceOfInteger::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("ChangeValue", (TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer)) &MeshVS_Array1OfSequenceOfInteger::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("__call__", (TColStd_SequenceOfInteger & (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer)) &MeshVS_Array1OfSequenceOfInteger::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("SetValue", (void (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer, const TColStd_SequenceOfInteger &)) &MeshVS_Array1OfSequenceOfInteger::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("Resize", (void (MeshVS_Array1OfSequenceOfInteger::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &MeshVS_Array1OfSequenceOfInteger::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_MeshVS_Array1OfSequenceOfInteger.def("__iter__", [](const MeshVS_Array1OfSequenceOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_Mesh.hxx
	py::class_<MeshVS_Mesh, opencascade::handle<MeshVS_Mesh>, AIS_InteractiveObject> cls_MeshVS_Mesh(mod, "MeshVS_Mesh", "the main class provides interface to create mesh presentation as a whole");
	cls_MeshVS_Mesh.def(py::init<>());
	cls_MeshVS_Mesh.def(py::init<const Standard_Boolean>(), py::arg("theIsAllowOverlapped"));
	cls_MeshVS_Mesh.def("Compute", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Presentation> &, const Standard_Integer)) &MeshVS_Mesh::Compute, "Computes presentation using builders added to sequence. Each builder computes own part of mesh presentation according to its type.", py::arg("PM"), py::arg("Prs"), py::arg("DisplayMode"));
	cls_MeshVS_Mesh.def("ComputeSelection", (void (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &MeshVS_Mesh::ComputeSelection, "Computes selection according to SelectMode", py::arg("Sel"), py::arg("SelectMode"));
	cls_MeshVS_Mesh.def("HilightSelected", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &MeshVS_Mesh::HilightSelected, "Draw selected owners presentation", py::arg("PM"), py::arg("Owners"));
	cls_MeshVS_Mesh.def("HilightOwnerWithColor", (void (MeshVS_Mesh::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &MeshVS_Mesh::HilightOwnerWithColor, "Draw hilighted owner presentation", py::arg("thePM"), py::arg("theColor"), py::arg("theOwner"));
	cls_MeshVS_Mesh.def("ClearSelected", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::ClearSelected, "Clears internal selection presentation");
	cls_MeshVS_Mesh.def("GetBuildersCount", (Standard_Integer (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetBuildersCount, "How many builders there are in sequence");
	cls_MeshVS_Mesh.def("GetBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::GetBuilder, "Returns builder by its index in sequence", py::arg("Index"));
	cls_MeshVS_Mesh.def("GetBuilderById", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::GetBuilderById, "Returns builder by its ID", py::arg("Id"));
	cls_MeshVS_Mesh.def("GetFreeId", (Standard_Integer (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetFreeId, "Returns the smallest positive ID, not occupied by any builder. This method using when builder is created with ID = -1");
	cls_MeshVS_Mesh.def("AddBuilder", [](MeshVS_Mesh &self, const opencascade::handle<MeshVS_PrsBuilder> & a0) -> void { return self.AddBuilder(a0); }, py::arg("Builder"));
	cls_MeshVS_Mesh.def("AddBuilder", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &, const Standard_Boolean)) &MeshVS_Mesh::AddBuilder, "Adds builder to tale of sequence. PrsBuilder is builder to be added If TreatAsHilighter is true, MeshVS_Mesh will use this builder to create presentation of hilighted and selected owners. Only one builder can be hilighter, so that if you call this method with TreatAsHilighter = Standard_True some times, only last builder will be hilighter WARNING: As minimum one builder must be added as hilighter, otherwise selection cannot be computed", py::arg("Builder"), py::arg("TreatAsHilighter"));
	cls_MeshVS_Mesh.def("SetHilighter", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_Mesh::SetHilighter, "Changes hilighter ( see above )", py::arg("Builder"));
	cls_MeshVS_Mesh.def("SetHilighter", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighter, "Sets builder with sequence index 'Index' as hilighter", py::arg("Index"));
	cls_MeshVS_Mesh.def("SetHilighterById", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::SetHilighterById, "Sets builder with identificator 'Id' as hilighter", py::arg("Id"));
	cls_MeshVS_Mesh.def("GetHilighter", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetHilighter, "Returns hilighter");
	cls_MeshVS_Mesh.def("RemoveBuilder", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilder, "Removes builder from sequence. If it is hilighter, hilighter will be NULL ( Don't remember to set it to other after!!! )", py::arg("Index"));
	cls_MeshVS_Mesh.def("RemoveBuilderById", (void (MeshVS_Mesh::*)(const Standard_Integer)) &MeshVS_Mesh::RemoveBuilderById, "Removes builder with identificator Id", py::arg("Id"));
	cls_MeshVS_Mesh.def("FindBuilder", (opencascade::handle<MeshVS_PrsBuilder> (MeshVS_Mesh::*)(const Standard_CString) const ) &MeshVS_Mesh::FindBuilder, "Finds builder by its type the string represents", py::arg("TypeString"));
	cls_MeshVS_Mesh.def("GetOwnerMaps", (const MeshVS_DataMapOfIntegerOwner & (MeshVS_Mesh::*)(const Standard_Boolean)) &MeshVS_Mesh::GetOwnerMaps, "Returns map of owners.", py::arg("IsElement"));
	cls_MeshVS_Mesh.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetDataSource, "Returns default builders' data source");
	cls_MeshVS_Mesh.def("SetDataSource", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_Mesh::SetDataSource, "Sets default builders' data source", py::arg("aDataSource"));
	cls_MeshVS_Mesh.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetDrawer, "Returns default builders' drawer");
	cls_MeshVS_Mesh.def("SetDrawer", (void (MeshVS_Mesh::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Mesh::SetDrawer, "Sets default builders' drawer", py::arg("aDrawer"));
	cls_MeshVS_Mesh.def("IsHiddenElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::IsHiddenElem, "Returns True if specified element is hidden By default no elements are hidden", py::arg("ID"));
	cls_MeshVS_Mesh.def("IsHiddenNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::IsHiddenNode, "Returns True if specified node is hidden. By default all nodes are hidden", py::arg("ID"));
	cls_MeshVS_Mesh.def("IsSelectableElem", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::IsSelectableElem, "Returns True if specified element is not hidden", py::arg("ID"));
	cls_MeshVS_Mesh.def("IsSelectableNode", (Standard_Boolean (MeshVS_Mesh::*)(const Standard_Integer) const ) &MeshVS_Mesh::IsSelectableNode, "Returns True if specified node is specified as selectable.", py::arg("ID"));
	cls_MeshVS_Mesh.def("GetHiddenNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetHiddenNodes, "Returns map of hidden nodes (may be null handle)");
	cls_MeshVS_Mesh.def("SetHiddenNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenNodes, "Sets map of hidden nodes, which shall not be displayed individually. If nodes shared by some elements shall not be drawn, they should be included into that map", py::arg("Ids"));
	cls_MeshVS_Mesh.def("GetHiddenElems", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetHiddenElems, "Returns map of hidden elements (may be null handle)");
	cls_MeshVS_Mesh.def("SetHiddenElems", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetHiddenElems, "Sets map of hidden elements", py::arg("Ids"));
	cls_MeshVS_Mesh.def("GetSelectableNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetSelectableNodes, "Returns map of selectable elements (may be null handle)");
	cls_MeshVS_Mesh.def("SetSelectableNodes", (void (MeshVS_Mesh::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_Mesh::SetSelectableNodes, "Sets map of selectable nodes.", py::arg("Ids"));
	cls_MeshVS_Mesh.def("UpdateSelectableNodes", (void (MeshVS_Mesh::*)()) &MeshVS_Mesh::UpdateSelectableNodes, "Automatically computes selectable nodes; the node is considered as being selectable if it is either not hidden, or is hidden but referred by at least one non-hidden element. Thus all nodes that are visible (either individually, or as ends or corners of elements) are selectable by default.");
	cls_MeshVS_Mesh.def("GetMeshSelMethod", (MeshVS_MeshSelectionMethod (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::GetMeshSelMethod, "Returns set mesh selection method (see MeshVS.cdl)");
	cls_MeshVS_Mesh.def("SetMeshSelMethod", (void (MeshVS_Mesh::*)(const MeshVS_MeshSelectionMethod)) &MeshVS_Mesh::SetMeshSelMethod, "Sets mesh selection method (see MeshVS.cdl)", py::arg("M"));
	cls_MeshVS_Mesh.def("IsWholeMeshOwner", (Standard_Boolean (MeshVS_Mesh::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &MeshVS_Mesh::IsWholeMeshOwner, "Returns True if the given owner represents a whole mesh.", py::arg("theOwner"));
	cls_MeshVS_Mesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_Mesh::get_type_name, "None");
	cls_MeshVS_Mesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Mesh::get_type_descriptor, "None");
	cls_MeshVS_Mesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Mesh::*)() const ) &MeshVS_Mesh::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataSource.hxx
	py::class_<MeshVS_DataSource, opencascade::handle<MeshVS_DataSource>, Standard_Transient> cls_MeshVS_DataSource(mod, "MeshVS_DataSource", "The deferred class using for the following tasks: 1) Receiving geometry data about single element of node by its number; 2) Receiving type of element or node by its number; 3) Receiving topological information about links between element and nodes it consist of; 4) Receiving information about what element cover this node; 5) Receiving information about all nodes and elements the object consist of 6) Activation of advanced mesh selection. In the advanced mesh selection mode there is created: - one owner for the whole mesh and for all selection modes - one sensitive entity for the whole mesh and for each selection mode Receiving of IDs of detected entities (nodes and elements) in a viewer is achieved by implementation of a group of methods GetDetectedEntities.");
	cls_MeshVS_DataSource.def("GetGeom", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean, TColStd_Array1OfReal &, Standard_Integer &, MeshVS_EntityType &) const ) &MeshVS_DataSource::GetGeom, "Returns geometry information about node or element ID is the numerical identificator of node or element IsElement indicates this ID describe node ( if Standard_False ) or element ( if Standard_True ) Coords is an array of co-ordinates of node(s). For node it is only 3 numbers: X, Y, Z in the strict order For element it is 3*n numbers, where n is number of this element vertices The order is strict also: X1, Y1, Z1, X2,...., where Xi, Yi, Zi are co-ordinates of vertices NbNodes is number of nodes. It is recommended this parameter to be set to 1 for node. Type is type of node or element (from enumeration). It is recommended this parameter to be set to MeshVS_ET_Node for node.", py::arg("ID"), py::arg("IsElement"), py::arg("Coords"), py::arg("NbNodes"), py::arg("Type"));
	cls_MeshVS_DataSource.def("GetGeomType", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean, MeshVS_EntityType &) const ) &MeshVS_DataSource::GetGeomType, "This method is similar to GetGeom, but returns only element or node type.", py::arg("ID"), py::arg("IsElement"), py::arg("Type"));
	cls_MeshVS_DataSource.def("Get3DGeom", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, Standard_Integer &, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &) const ) &MeshVS_DataSource::Get3DGeom, "This method returns topology information about 3D-element Returns false if element with ID isn't 3D or because other troubles", py::arg("ID"), py::arg("NbNodes"), py::arg("Data"));
	cls_MeshVS_DataSource.def("GetAddr", (Standard_Address (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean) const ) &MeshVS_DataSource::GetAddr, "This method returns pointer which represents element or node data structure. This address will be saved in MeshVS_MeshEntityOwner, so that you can access to data structure fast by the method Owner(). In the redefined method you can return NULL. ID is the numerical identificator of node or element IsElement indicates this ID describe node ( if Standard_False ) or element ( if Standard_True )", py::arg("ID"), py::arg("IsElement"));
	cls_MeshVS_DataSource.def("GetNodesByElement", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, TColStd_Array1OfInteger &, Standard_Integer &) const ) &MeshVS_DataSource::GetNodesByElement, "This method returns information about nodes this element consist of. ID is the numerical identificator of element. NodeIDs is the output array of nodes IDs in correct order, the same as coordinates returned by GetGeom(). NbNodes is number of nodes (number of items set in NodeIDs). Returns False if element does not exist", py::arg("ID"), py::arg("NodeIDs"), py::arg("NbNodes"));
	cls_MeshVS_DataSource.def("GetAllNodes", (const TColStd_PackedMapOfInteger & (MeshVS_DataSource::*)() const ) &MeshVS_DataSource::GetAllNodes, "This method returns map of all nodes the object consist of.");
	cls_MeshVS_DataSource.def("GetAllElements", (const TColStd_PackedMapOfInteger & (MeshVS_DataSource::*)() const ) &MeshVS_DataSource::GetAllElements, "This method returns map of all elements the object consist of.");
	cls_MeshVS_DataSource.def("GetNormal", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &) const ) &MeshVS_DataSource::GetNormal, "This method calculates normal of face, which is using for correct reflection presentation. There is default method, for advance reflection this method can be redefined. Id is the numerical identificator of only element! Max is maximal number of nodes an element can consist of nx, ny, nz are values whose represent co-ordinates of normal (will be returned) In the redefined method you can return normal with length more then 1, but in this case the appearance of element will be more bright than usual. For ordinary brightness you must return normal with length 1", py::arg("Id"), py::arg("Max"), py::arg("nx"), py::arg("ny"), py::arg("nz"));
	cls_MeshVS_DataSource.def("GetNodeNormal", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &) const ) &MeshVS_DataSource::GetNodeNormal, "This method return normal of node ranknode of face Id, which is using for smooth shading presentation. Returns false if normal isn't defined.", py::arg("ranknode"), py::arg("ElementId"), py::arg("nx"), py::arg("ny"), py::arg("nz"));
	cls_MeshVS_DataSource.def("GetNormalsByElement", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer, opencascade::handle<TColStd_HArray1OfReal> &) const ) &MeshVS_DataSource::GetNormalsByElement, "This method puts components of normal vectors at each node of a mesh face (at each face of a mesh volume) into the output array. Returns false if some problem was detected during calculation of normals. Id is an identifier of the mesh element. IsNodal, when true, means that normals at mesh element nodes are needed. If nodal normals are not available, or IsNodal is false, or the mesh element is a volume, then the output array contents depend on the element type: face: a normal calculated by GetNormal() is duplicated for each node of the face; volume: normals to all faces of the volume are computed (not for each node!). MaxNodes is maximal number of nodes an element can consist of. Normals contains the result.", py::arg("Id"), py::arg("IsNodal"), py::arg("MaxNodes"), py::arg("Normals"));
	cls_MeshVS_DataSource.def("GetAllGroups", (void (MeshVS_DataSource::*)(TColStd_PackedMapOfInteger &) const ) &MeshVS_DataSource::GetAllGroups, "This method returns map of all groups the object contains.", py::arg("Ids"));
	cls_MeshVS_DataSource.def("GetGroup", (Standard_Boolean (MeshVS_DataSource::*)(const Standard_Integer, MeshVS_EntityType &, TColStd_PackedMapOfInteger &) const ) &MeshVS_DataSource::GetGroup, "This method returns map of all group elements.", py::arg("Id"), py::arg("Type"), py::arg("Ids"));
	cls_MeshVS_DataSource.def("GetGroupAddr", (Standard_Address (MeshVS_DataSource::*)(const Standard_Integer) const ) &MeshVS_DataSource::GetGroupAddr, "This method returns pointer which represents group data structure. This address will be saved in MeshVS_MeshOwner, so that you can access to data structure fast by the method Owner(). In the redefined method you can return NULL. ID is the numerical identificator of group", py::arg("ID"));
	cls_MeshVS_DataSource.def("IsAdvancedSelectionEnabled", (Standard_Boolean (MeshVS_DataSource::*)() const ) &MeshVS_DataSource::IsAdvancedSelectionEnabled, "Returns True if advanced mesh selection is enabled. Default implementation returns False. It should be redefined to return True for advanced mesh selection activation.");
	cls_MeshVS_DataSource.def("GetBoundingBox", (Bnd_Box (MeshVS_DataSource::*)() const ) &MeshVS_DataSource::GetBoundingBox, "Returns the bounding box of the whole mesh. It is used in advanced selection mode to define roughly the sensitive area of the mesh. It can be redefined to get access to a box computed in advance.");
	cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Standard_Real, const Standard_Real, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &, Standard_Real &)) &MeshVS_DataSource::GetDetectedEntities, "Returns maps of entities (nodes and elements) detected by mouse click at the point (X,Y) on the current view plane, with the tolerance aTol. DMin - is out argument should return actual detection tolerance. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("X"), py::arg("Y"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"), py::arg("DMin"));
	cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Returns maps of entities (nodes and elements) detected by mouse selection with rectangular box (XMin, YMin, XMax, YMax) on the current veiw plane, with the tolerance aTol. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("XMin"), py::arg("YMin"), py::arg("XMax"), py::arg("YMax"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"));
	cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, const TColgp_Array1OfPnt2d &, const Bnd_Box2d &, const Standard_Real, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Returns maps of entities (nodes and elements) detected by mouse selection with the polyline <Polyline> on the current veiw plane, with the tolerance aTol. Returns True if something is detected. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("Polyline"), py::arg("aBox"), py::arg("aTol"), py::arg("Nodes"), py::arg("Elements"));
	cls_MeshVS_DataSource.def("GetDetectedEntities", (Standard_Boolean (MeshVS_DataSource::*)(const opencascade::handle<MeshVS_Mesh> &, opencascade::handle<TColStd_HPackedMapOfInteger> &, opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_DataSource::GetDetectedEntities, "Filter out the maps of mesh entities so as to keep only the entities that are allowed to be selected according to the current context. Returns True if any of the maps has been changed. It should be redefined if the advanced mesh selection is activated. Default implementation returns False.", py::arg("Prs"), py::arg("Nodes"), py::arg("Elements"));
	cls_MeshVS_DataSource.def_static("get_type_name_", (const char * (*)()) &MeshVS_DataSource::get_type_name, "None");
	cls_MeshVS_DataSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DataSource::get_type_descriptor, "None");
	cls_MeshVS_DataSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DataSource::*)() const ) &MeshVS_DataSource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_Drawer.hxx
	py::class_<MeshVS_Drawer, opencascade::handle<MeshVS_Drawer>, Standard_Transient> cls_MeshVS_Drawer(mod, "MeshVS_Drawer", "This class provided the common interface to share between classes big set of constants affecting to object appearance. By default, this class can store integers, doubles, OCC colors, OCC materials. Each of OCC enum members can be stored as integers.");
	cls_MeshVS_Drawer.def("Assign", (void (MeshVS_Drawer::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_Drawer::Assign, "This method copies other drawer contents to this.", py::arg("aDrawer"));
	cls_MeshVS_Drawer.def("SetInteger", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_Drawer::SetInteger, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("SetDouble", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Real)) &MeshVS_Drawer::SetDouble, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("SetBoolean", (void (MeshVS_Drawer::*)(const Standard_Integer, const Standard_Boolean)) &MeshVS_Drawer::SetBoolean, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("SetColor", (void (MeshVS_Drawer::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_Drawer::SetColor, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("SetMaterial", (void (MeshVS_Drawer::*)(const Standard_Integer, const Graphic3d_MaterialAspect &)) &MeshVS_Drawer::SetMaterial, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("SetAsciiString", (void (MeshVS_Drawer::*)(const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_Drawer::SetAsciiString, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetInteger", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Standard_Integer &) const ) &MeshVS_Drawer::GetInteger, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetDouble", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Standard_Real &) const ) &MeshVS_Drawer::GetDouble, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetBoolean", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Standard_Boolean &) const ) &MeshVS_Drawer::GetBoolean, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Quantity_Color &) const ) &MeshVS_Drawer::GetColor, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, Graphic3d_MaterialAspect &) const ) &MeshVS_Drawer::GetMaterial, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("GetAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer, TCollection_AsciiString &) const ) &MeshVS_Drawer::GetAsciiString, "None", py::arg("Key"), py::arg("Value"));
	cls_MeshVS_Drawer.def("RemoveInteger", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveInteger, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def("RemoveDouble", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveDouble, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def("RemoveBoolean", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveBoolean, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def("RemoveColor", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveColor, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def("RemoveMaterial", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveMaterial, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def("RemoveAsciiString", (Standard_Boolean (MeshVS_Drawer::*)(const Standard_Integer)) &MeshVS_Drawer::RemoveAsciiString, "None", py::arg("Key"));
	cls_MeshVS_Drawer.def_static("get_type_name_", (const char * (*)()) &MeshVS_Drawer::get_type_name, "None");
	cls_MeshVS_Drawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_Drawer::get_type_descriptor, "None");
	cls_MeshVS_Drawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_Drawer::*)() const ) &MeshVS_Drawer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_PrsBuilder.hxx
	py::class_<MeshVS_PrsBuilder, opencascade::handle<MeshVS_PrsBuilder>, Standard_Transient> cls_MeshVS_PrsBuilder(mod, "MeshVS_PrsBuilder", "This class is parent for all builders using in MeshVS_Mesh. It provides base fields and methods all buildes need.");
	cls_MeshVS_PrsBuilder.def("Build", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_PrsBuilder::Build, "Builds presentation of certain type of data. Prs is presentation object which this method constructs. IDs is set of numeric identificators forming object appearance. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. IsElement indicates, IDs is identificators of nodes or elements. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
	cls_MeshVS_PrsBuilder.def("CustomBuild", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const ) &MeshVS_PrsBuilder::CustomBuild, "This method is called to build presentation of custom elements (they have MeshVS_ET_0D type). IDs is set of numeric identificators of elements for custom building. IDsToExclude is set of IDs to exclude from processing. If some entity has been excluded, it is not processed by other builders. DisplayMode is numeric constant describing display mode (see MeshVS_DisplayModeFlags.hxx)", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
	cls_MeshVS_PrsBuilder.def("CustomSensitiveEntity", (opencascade::handle<SelectBasics_SensitiveEntity> (MeshVS_PrsBuilder::*)(const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Integer) const ) &MeshVS_PrsBuilder::CustomSensitiveEntity, "This method is called to build sensitive of custom elements ( they have MeshVS_ET_0D type )", py::arg("Owner"), py::arg("SelectMode"));
	cls_MeshVS_PrsBuilder.def("GetFlags", (Standard_Integer (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetFlags, "Returns flags, assigned with builder during creation");
	cls_MeshVS_PrsBuilder.def("TestFlags", (Standard_Boolean (MeshVS_PrsBuilder::*)(const Standard_Integer) const ) &MeshVS_PrsBuilder::TestFlags, "Test whether display mode has flags assigned with this builder. This method has default implementation and can be redefined for advance behavior Returns Standard_True only if display mode is appropriate for this builder", py::arg("DisplayMode"));
	cls_MeshVS_PrsBuilder.def("GetId", (Standard_Integer (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetId, "Returns builder ID");
	cls_MeshVS_PrsBuilder.def("GetPriority", (Standard_Integer (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetPriority, "Returns priority; as priority bigger, as soon builder will be called.");
	cls_MeshVS_PrsBuilder.def("GetDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetDataSource, "Returns custom data source or default ( from MeshVS_Mesh ) if custom is NULL");
	cls_MeshVS_PrsBuilder.def("SetDataSource", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_PrsBuilder::SetDataSource, "Change custom data source", py::arg("newDS"));
	cls_MeshVS_PrsBuilder.def("GetDrawer", (opencascade::handle<MeshVS_Drawer> (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetDrawer, "Returns custom drawer or default ( from MeshVS_Mesh ) if custom is NULL");
	cls_MeshVS_PrsBuilder.def("SetDrawer", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<MeshVS_Drawer> &)) &MeshVS_PrsBuilder::SetDrawer, "Change custom drawer", py::arg("newDr"));
	cls_MeshVS_PrsBuilder.def("SetExcluding", (void (MeshVS_PrsBuilder::*)(const Standard_Boolean)) &MeshVS_PrsBuilder::SetExcluding, "Set excluding state. If it is Standard_True, the nodes or elements, processed by current builder will be noted and next builder won't process its.", py::arg("state"));
	cls_MeshVS_PrsBuilder.def("IsExcludingOn", (Standard_Boolean (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::IsExcludingOn, "Read excluding state");
	cls_MeshVS_PrsBuilder.def("SetPresentationManager", (void (MeshVS_PrsBuilder::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &MeshVS_PrsBuilder::SetPresentationManager, "Set presentation manager for builder", py::arg("thePrsMgr"));
	cls_MeshVS_PrsBuilder.def("GetPresentationManager", (opencascade::handle<PrsMgr_PresentationManager3d> (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::GetPresentationManager, "Get presentation manager of builder");
	cls_MeshVS_PrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_PrsBuilder::get_type_name, "None");
	cls_MeshVS_PrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_PrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_PrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_PrsBuilder::*)() const ) &MeshVS_PrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_CommonSensitiveEntity.hxx
	py::class_<MeshVS_CommonSensitiveEntity, opencascade::handle<MeshVS_CommonSensitiveEntity>, Select3D_SensitiveSet> cls_MeshVS_CommonSensitiveEntity(mod, "MeshVS_CommonSensitiveEntity", "Sensitive entity covering entire mesh for global selection.");
	cls_MeshVS_CommonSensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<MeshVS_Mesh> &, const MeshVS_MeshSelectionMethod>(), py::arg("theOwner"), py::arg("theParentMesh"), py::arg("theSelMethod"));
	cls_MeshVS_CommonSensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::NbSubElements, "Number of elements.");
	cls_MeshVS_CommonSensitiveEntity.def("Size", (Standard_Integer (MeshVS_CommonSensitiveEntity::*)() const ) &MeshVS_CommonSensitiveEntity::Size, "Returns the amount of sub-entities of the complex entity");
	cls_MeshVS_CommonSensitiveEntity.def("Box", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer) const ) &MeshVS_CommonSensitiveEntity::Box, "Returns bounding box of sub-entity with index theIdx in sub-entity list", py::arg("theIdx"));
	cls_MeshVS_CommonSensitiveEntity.def("Center", (Standard_Real (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer) const ) &MeshVS_CommonSensitiveEntity::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_MeshVS_CommonSensitiveEntity.def("Swap", (void (MeshVS_CommonSensitiveEntity::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_CommonSensitiveEntity::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_MeshVS_CommonSensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_CommonSensitiveEntity::*)()) &MeshVS_CommonSensitiveEntity::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
	cls_MeshVS_CommonSensitiveEntity.def("CenterOfGeometry", (gp_Pnt (MeshVS_CommonSensitiveEntity::*)() const ) &MeshVS_CommonSensitiveEntity::CenterOfGeometry, "Returns center of a mesh");
	cls_MeshVS_CommonSensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_CommonSensitiveEntity::get_type_name, "None");
	cls_MeshVS_CommonSensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_CommonSensitiveEntity::get_type_descriptor, "None");
	cls_MeshVS_CommonSensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_CommonSensitiveEntity::*)() const ) &MeshVS_CommonSensitiveEntity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MeshEntityOwner.hxx
	py::class_<MeshVS_MeshEntityOwner, opencascade::handle<MeshVS_MeshEntityOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshEntityOwner(mod, "MeshVS_MeshEntityOwner", "The custom owner. This class provides methods to store owner information: 1) An address of element or node data structure 2) Type of node or element owner assigned 3) ID of node or element owner assigned");
	cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"));
	cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"));
	cls_MeshVS_MeshEntityOwner.def(py::init<const SelectMgr_SOPtr &, const Standard_Integer, const Standard_Address, const MeshVS_EntityType &, const Standard_Integer, const Standard_Boolean>(), py::arg("SelObj"), py::arg("ID"), py::arg("MeshEntity"), py::arg("Type"), py::arg("Priority"), py::arg("IsGroup"));
	cls_MeshVS_MeshEntityOwner.def("Owner", (Standard_Address (MeshVS_MeshEntityOwner::*)() const ) &MeshVS_MeshEntityOwner::Owner, "Returns an address of element or node data structure");
	cls_MeshVS_MeshEntityOwner.def("Type", (MeshVS_EntityType (MeshVS_MeshEntityOwner::*)() const ) &MeshVS_MeshEntityOwner::Type, "Returns type of element or node data structure");
	cls_MeshVS_MeshEntityOwner.def("ID", (Standard_Integer (MeshVS_MeshEntityOwner::*)() const ) &MeshVS_MeshEntityOwner::ID, "Returns ID of element or node data structure");
	cls_MeshVS_MeshEntityOwner.def("IsGroup", (Standard_Boolean (MeshVS_MeshEntityOwner::*)() const ) &MeshVS_MeshEntityOwner::IsGroup, "Returns true if owner represents group of nodes or elements");
	cls_MeshVS_MeshEntityOwner.def("IsHilighted", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); }, py::arg("PM"));
	cls_MeshVS_MeshEntityOwner.def("IsHilighted", (Standard_Boolean (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const ) &MeshVS_MeshEntityOwner::IsHilighted, "Returns true if owner is hilighted", py::arg("PM"), py::arg("Mode"));
	cls_MeshVS_MeshEntityOwner.def("HilightWithColor", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); }, py::arg("thePM"), py::arg("theStyle"));
	cls_MeshVS_MeshEntityOwner.def("HilightWithColor", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::HilightWithColor, "Hilights owner with the certain color", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
	cls_MeshVS_MeshEntityOwner.def("Unhilight", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); }, py::arg("PM"));
	cls_MeshVS_MeshEntityOwner.def("Unhilight", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Unhilight, "Strip hilight of owner", py::arg("PM"), py::arg("Mode"));
	cls_MeshVS_MeshEntityOwner.def("Clear", [](MeshVS_MeshEntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); }, py::arg("PM"));
	cls_MeshVS_MeshEntityOwner.def("Clear", (void (MeshVS_MeshEntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshEntityOwner::Clear, "None", py::arg("PM"), py::arg("Mode"));
	cls_MeshVS_MeshEntityOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshEntityOwner::get_type_name, "None");
	cls_MeshVS_MeshEntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshEntityOwner::get_type_descriptor, "None");
	cls_MeshVS_MeshEntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshEntityOwner::*)() const ) &MeshVS_MeshEntityOwner::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataSource3D.hxx
	py::class_<MeshVS_DataSource3D, opencascade::handle<MeshVS_DataSource3D>, MeshVS_DataSource> cls_MeshVS_DataSource3D(mod, "MeshVS_DataSource3D", "None");
	cls_MeshVS_DataSource3D.def("GetPrismTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const ) &MeshVS_DataSource3D::GetPrismTopology, "None", py::arg("BasePoints"));
	cls_MeshVS_DataSource3D.def("GetPyramidTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const ) &MeshVS_DataSource3D::GetPyramidTopology, "None", py::arg("BasePoints"));
	cls_MeshVS_DataSource3D.def_static("CreatePrismTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePrismTopology, "None", py::arg("BasePoints"));
	cls_MeshVS_DataSource3D.def_static("CreatePyramidTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePyramidTopology, "None", py::arg("BasePoints"));
	cls_MeshVS_DataSource3D.def_static("get_type_name_", (const char * (*)()) &MeshVS_DataSource3D::get_type_name, "None");
	cls_MeshVS_DataSource3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DataSource3D::get_type_descriptor, "None");
	cls_MeshVS_DataSource3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DataSource3D::*)() const ) &MeshVS_DataSource3D::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DeformedDataSource.hxx
	py::class_<MeshVS_DeformedDataSource, opencascade::handle<MeshVS_DeformedDataSource>, MeshVS_DataSource> cls_MeshVS_DeformedDataSource(mod, "MeshVS_DeformedDataSource", "The class provides default class which helps to represent node displacements by deformed mesh This class has an internal handle to canonical non-deformed mesh data source and map of displacement vectors. The displacement can be magnified to useful size. All methods is implemented with calling the corresponding methods of non-deformed data source.");
	cls_MeshVS_DeformedDataSource.def(py::init<const opencascade::handle<MeshVS_DataSource> &, const Standard_Real>(), py::arg("theNonDeformDS"), py::arg("theMagnify"));
	cls_MeshVS_DeformedDataSource.def("GetGeom", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, const Standard_Boolean, TColStd_Array1OfReal &, Standard_Integer &, MeshVS_EntityType &) const ) &MeshVS_DeformedDataSource::GetGeom, "None", py::arg("ID"), py::arg("IsElement"), py::arg("Coords"), py::arg("NbNodes"), py::arg("Type"));
	cls_MeshVS_DeformedDataSource.def("GetGeomType", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, const Standard_Boolean, MeshVS_EntityType &) const ) &MeshVS_DeformedDataSource::GetGeomType, "None", py::arg("ID"), py::arg("IsElement"), py::arg("Type"));
	cls_MeshVS_DeformedDataSource.def("Get3DGeom", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, Standard_Integer &, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &) const ) &MeshVS_DeformedDataSource::Get3DGeom, "None", py::arg("ID"), py::arg("NbNodes"), py::arg("Data"));
	cls_MeshVS_DeformedDataSource.def("GetAddr", (Standard_Address (MeshVS_DeformedDataSource::*)(const Standard_Integer, const Standard_Boolean) const ) &MeshVS_DeformedDataSource::GetAddr, "None", py::arg("ID"), py::arg("IsElement"));
	cls_MeshVS_DeformedDataSource.def("GetNodesByElement", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, TColStd_Array1OfInteger &, Standard_Integer &) const ) &MeshVS_DeformedDataSource::GetNodesByElement, "None", py::arg("ID"), py::arg("NodeIDs"), py::arg("NbNodes"));
	cls_MeshVS_DeformedDataSource.def("GetAllNodes", (const TColStd_PackedMapOfInteger & (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::GetAllNodes, "None");
	cls_MeshVS_DeformedDataSource.def("GetAllElements", (const TColStd_PackedMapOfInteger & (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::GetAllElements, "None");
	cls_MeshVS_DeformedDataSource.def("GetVectors", (const MeshVS_DataMapOfIntegerVector & (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::GetVectors, "This method returns map of nodal displacement vectors");
	cls_MeshVS_DeformedDataSource.def("SetVectors", (void (MeshVS_DeformedDataSource::*)(const MeshVS_DataMapOfIntegerVector &)) &MeshVS_DeformedDataSource::SetVectors, "This method sets map of nodal displacement vectors (Map).", py::arg("Map"));
	cls_MeshVS_DeformedDataSource.def("GetVector", (Standard_Boolean (MeshVS_DeformedDataSource::*)(const Standard_Integer, gp_Vec &) const ) &MeshVS_DeformedDataSource::GetVector, "This method returns vector ( Vect ) assigned to node number ID.", py::arg("ID"), py::arg("Vect"));
	cls_MeshVS_DeformedDataSource.def("SetVector", (void (MeshVS_DeformedDataSource::*)(const Standard_Integer, const gp_Vec &)) &MeshVS_DeformedDataSource::SetVector, "This method sets vector ( Vect ) assigned to node number ID.", py::arg("ID"), py::arg("Vect"));
	cls_MeshVS_DeformedDataSource.def("SetNonDeformedDataSource", (void (MeshVS_DeformedDataSource::*)(const opencascade::handle<MeshVS_DataSource> &)) &MeshVS_DeformedDataSource::SetNonDeformedDataSource, "None", py::arg("theDS"));
	cls_MeshVS_DeformedDataSource.def("GetNonDeformedDataSource", (opencascade::handle<MeshVS_DataSource> (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::GetNonDeformedDataSource, "With this methods you can read and change internal canonical data source");
	cls_MeshVS_DeformedDataSource.def("SetMagnify", (void (MeshVS_DeformedDataSource::*)(const Standard_Real)) &MeshVS_DeformedDataSource::SetMagnify, "None", py::arg("theMagnify"));
	cls_MeshVS_DeformedDataSource.def("GetMagnify", (Standard_Real (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::GetMagnify, "With this methods you can read and change magnify coefficient of nodal displacements");
	cls_MeshVS_DeformedDataSource.def_static("get_type_name_", (const char * (*)()) &MeshVS_DeformedDataSource::get_type_name, "None");
	cls_MeshVS_DeformedDataSource.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DeformedDataSource::get_type_descriptor, "None");
	cls_MeshVS_DeformedDataSource.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DeformedDataSource::*)() const ) &MeshVS_DeformedDataSource::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DummySensitiveEntity.hxx
	py::class_<MeshVS_DummySensitiveEntity, opencascade::handle<MeshVS_DummySensitiveEntity>, SelectBasics_SensitiveEntity> cls_MeshVS_DummySensitiveEntity(mod, "MeshVS_DummySensitiveEntity", "This class allows to create owners to all elements or nodes, both hidden and shown, but these owners user cannot select 'by hands' in viewer. They means for internal application tasks, for example, receiving all owners, both for hidden and shown entities.");
	cls_MeshVS_DummySensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
	cls_MeshVS_DummySensitiveEntity.def("Matches", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_DummySensitiveEntity::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
	cls_MeshVS_DummySensitiveEntity.def("NbSubElements", (Standard_Integer (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::NbSubElements, "None");
	cls_MeshVS_DummySensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BoundingBox, "None");
	cls_MeshVS_DummySensitiveEntity.def("BVH", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::BVH, "None");
	cls_MeshVS_DummySensitiveEntity.def("Clear", (void (MeshVS_DummySensitiveEntity::*)()) &MeshVS_DummySensitiveEntity::Clear, "None");
	cls_MeshVS_DummySensitiveEntity.def("HasInitLocation", (Standard_Boolean (MeshVS_DummySensitiveEntity::*)() const ) &MeshVS_DummySensitiveEntity::HasInitLocation, "None");
	cls_MeshVS_DummySensitiveEntity.def("InvInitLocation", (gp_GTrsf (MeshVS_DummySensitiveEntity::*)() const ) &MeshVS_DummySensitiveEntity::InvInitLocation, "None");
	cls_MeshVS_DummySensitiveEntity.def_static("get_type_name_", (const char * (*)()) &MeshVS_DummySensitiveEntity::get_type_name, "None");
	cls_MeshVS_DummySensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DummySensitiveEntity::get_type_descriptor, "None");
	cls_MeshVS_DummySensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DummySensitiveEntity::*)() const ) &MeshVS_DummySensitiveEntity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_ElementalColorPrsBuilder.hxx
	py::class_<MeshVS_ElementalColorPrsBuilder, opencascade::handle<MeshVS_ElementalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_ElementalColorPrsBuilder(mod, "MeshVS_ElementalColorPrsBuilder", "This class provides methods to create presentation of elements with assigned colors. The class contains two color maps: map of same colors for front and back side of face and map of different ones,");
	cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
	cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
	cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
	cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
	cls_MeshVS_ElementalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
	cls_MeshVS_ElementalColorPrsBuilder.def("Build", (void (MeshVS_ElementalColorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_ElementalColorPrsBuilder::Build, "Builds presentation of elements with assigned colors.", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
	cls_MeshVS_ElementalColorPrsBuilder.def("GetColors1", (const MeshVS_DataMapOfIntegerColor & (MeshVS_ElementalColorPrsBuilder::*)() const ) &MeshVS_ElementalColorPrsBuilder::GetColors1, "Returns map of colors same for front and back side of face.");
	cls_MeshVS_ElementalColorPrsBuilder.def("SetColors1", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_ElementalColorPrsBuilder::SetColors1, "Sets map of colors same for front and back side of face.", py::arg("Map"));
	cls_MeshVS_ElementalColorPrsBuilder.def("HasColors1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const ) &MeshVS_ElementalColorPrsBuilder::HasColors1, "Returns true, if map of colors isn't empty");
	cls_MeshVS_ElementalColorPrsBuilder.def("GetColor1", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &) const ) &MeshVS_ElementalColorPrsBuilder::GetColor1, "Returns color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
	cls_MeshVS_ElementalColorPrsBuilder.def("SetColor1", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor1, "Sets color assigned with element number ID", py::arg("ID"), py::arg("theColor"));
	cls_MeshVS_ElementalColorPrsBuilder.def("GetColors2", (const MeshVS_DataMapOfIntegerTwoColors & (MeshVS_ElementalColorPrsBuilder::*)() const ) &MeshVS_ElementalColorPrsBuilder::GetColors2, "Returns map of different colors for front and back side of face");
	cls_MeshVS_ElementalColorPrsBuilder.def("SetColors2", (void (MeshVS_ElementalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColors2, "Sets map of different colors for front and back side of face", py::arg("Map"));
	cls_MeshVS_ElementalColorPrsBuilder.def("HasColors2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)() const ) &MeshVS_ElementalColorPrsBuilder::HasColors2, "Returns true, if map isn't empty");
	cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, MeshVS_TwoColors &) const ) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID", py::arg("ID"), py::arg("theColor"));
	cls_MeshVS_ElementalColorPrsBuilder.def("GetColor2", (Standard_Boolean (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &, Quantity_Color &) const ) &MeshVS_ElementalColorPrsBuilder::GetColor2, "Returns colors assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
	cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const MeshVS_TwoColors &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets colors assigned with element number ID", py::arg("ID"), py::arg("theTwoColors"));
	cls_MeshVS_ElementalColorPrsBuilder.def("SetColor2", (void (MeshVS_ElementalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &, const Quantity_Color &)) &MeshVS_ElementalColorPrsBuilder::SetColor2, "Sets color assigned with element number ID theColor1 is the front element color theColor2 is the back element color", py::arg("ID"), py::arg("theColor1"), py::arg("theColor2"));
	cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_name, "None");
	cls_MeshVS_ElementalColorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_ElementalColorPrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_ElementalColorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_ElementalColorPrsBuilder::*)() const ) &MeshVS_ElementalColorPrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoNodes.hxx
	py::class_<MeshVS_TwoNodes, std::unique_ptr<MeshVS_TwoNodes, Deleter<MeshVS_TwoNodes>>> cls_MeshVS_TwoNodes(mod, "MeshVS_TwoNodes", "Structure containing two IDs (of nodes) for using as a key in a map (as representation of a mesh link)");
	cls_MeshVS_TwoNodes.def(py::init<>());
	cls_MeshVS_TwoNodes.def(py::init<Standard_Integer>(), py::arg("aFirst"));
	cls_MeshVS_TwoNodes.def(py::init<Standard_Integer, Standard_Integer>(), py::arg("aFirst"), py::arg("aSecond"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MeshOwner.hxx
	py::class_<MeshVS_MeshOwner, opencascade::handle<MeshVS_MeshOwner>, SelectMgr_EntityOwner> cls_MeshVS_MeshOwner(mod, "MeshVS_MeshOwner", "The custom mesh owner used for advanced mesh selection. This class provides methods to store information: 1) IDs of hilighted mesh nodes and elements 2) IDs of mesh nodes and elements selected on the mesh");
	cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("theSelObj"), py::arg("theDS"));
	cls_MeshVS_MeshOwner.def(py::init<const SelectMgr_SOPtr &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("theSelObj"), py::arg("theDS"), py::arg("thePriority"));
	cls_MeshVS_MeshOwner.def("GetDataSource", (const opencascade::handle<MeshVS_DataSource> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::GetDataSource, "None");
	cls_MeshVS_MeshOwner.def("GetSelectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::GetSelectedNodes, "Returns ids of selected mesh nodes");
	cls_MeshVS_MeshOwner.def("GetSelectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::GetSelectedElements, "Returns ids of selected mesh elements");
	cls_MeshVS_MeshOwner.def("AddSelectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::AddSelectedEntities, "Saves ids of selected mesh entities", py::arg("Nodes"), py::arg("Elems"));
	cls_MeshVS_MeshOwner.def("ClearSelectedEntities", (void (MeshVS_MeshOwner::*)()) &MeshVS_MeshOwner::ClearSelectedEntities, "Clears ids of selected mesh entities");
	cls_MeshVS_MeshOwner.def("GetDetectedNodes", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::GetDetectedNodes, "Returns ids of hilighted mesh nodes");
	cls_MeshVS_MeshOwner.def("GetDetectedElements", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::GetDetectedElements, "Returns ids of hilighted mesh elements");
	cls_MeshVS_MeshOwner.def("SetDetectedEntities", (void (MeshVS_MeshOwner::*)(const opencascade::handle<TColStd_HPackedMapOfInteger> &, const opencascade::handle<TColStd_HPackedMapOfInteger> &)) &MeshVS_MeshOwner::SetDetectedEntities, "Saves ids of hilighted mesh entities", py::arg("Nodes"), py::arg("Elems"));
	cls_MeshVS_MeshOwner.def("HilightWithColor", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); }, py::arg("thePM"), py::arg("theColor"));
	cls_MeshVS_MeshOwner.def("HilightWithColor", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &MeshVS_MeshOwner::HilightWithColor, "None", py::arg("thePM"), py::arg("theColor"), py::arg("theMode"));
	cls_MeshVS_MeshOwner.def("Unhilight", [](MeshVS_MeshOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); }, py::arg("PM"));
	cls_MeshVS_MeshOwner.def("Unhilight", (void (MeshVS_MeshOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &MeshVS_MeshOwner::Unhilight, "None", py::arg("PM"), py::arg("Mode"));
	cls_MeshVS_MeshOwner.def("IsForcedHilight", (Standard_Boolean (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::IsForcedHilight, "None");
	cls_MeshVS_MeshOwner.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshOwner::get_type_name, "None");
	cls_MeshVS_MeshOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshOwner::get_type_descriptor, "None");
	cls_MeshVS_MeshOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshOwner::*)() const ) &MeshVS_MeshOwner::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MeshPrsBuilder.hxx
	py::class_<MeshVS_MeshPrsBuilder, opencascade::handle<MeshVS_MeshPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_MeshPrsBuilder(mod, "MeshVS_MeshPrsBuilder", "This class provides methods to compute base mesh presentation");
	cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
	cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
	cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
	cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
	cls_MeshVS_MeshPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
	cls_MeshVS_MeshPrsBuilder.def("Build", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_MeshPrsBuilder::Build, "Builds base mesh presentation by calling the methods below", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
	cls_MeshVS_MeshPrsBuilder.def("BuildNodes", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const ) &MeshVS_MeshPrsBuilder::BuildNodes, "Builds nodes presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
	cls_MeshVS_MeshPrsBuilder.def("BuildElements", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Integer) const ) &MeshVS_MeshPrsBuilder::BuildElements, "Builds elements presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("DisplayMode"));
	cls_MeshVS_MeshPrsBuilder.def("BuildHilightPrs", (void (MeshVS_MeshPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, const Standard_Boolean) const ) &MeshVS_MeshPrsBuilder::BuildHilightPrs, "Builds presentation of hilighted entity", py::arg("Prs"), py::arg("IDs"), py::arg("IsElement"));
	cls_MeshVS_MeshPrsBuilder.def_static("AddVolumePrs_", (void (*)(const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &, const TColStd_Array1OfReal &, const Standard_Integer, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real)) &MeshVS_MeshPrsBuilder::AddVolumePrs, "Add to array polygons or polylines representing volume", py::arg("Topo"), py::arg("Nodes"), py::arg("NbNodes"), py::arg("Array"), py::arg("IsReflected"), py::arg("IsShrinked"), py::arg("IsSelect"), py::arg("ShrinkCoef"));
	cls_MeshVS_MeshPrsBuilder.def_static("HowManyPrimitives_", (void (*)(const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, Standard_Integer &, Standard_Integer &)) &MeshVS_MeshPrsBuilder::HowManyPrimitives, "Calculate how many polygons or polylines are necessary to draw passed topology", py::arg("Topo"), py::arg("AsPolygons"), py::arg("IsSelect"), py::arg("NbNodes"), py::arg("Vertices"), py::arg("Bounds"));
	cls_MeshVS_MeshPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_MeshPrsBuilder::get_type_name, "None");
	cls_MeshVS_MeshPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_MeshPrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_MeshPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_MeshPrsBuilder::*)() const ) &MeshVS_MeshPrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_NodalColorPrsBuilder.hxx
	py::class_<MeshVS_NodalColorPrsBuilder, opencascade::handle<MeshVS_NodalColorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_NodalColorPrsBuilder(mod, "MeshVS_NodalColorPrsBuilder", "This class provides methods to create presentation of nodes with assigned color. There are two ways of presentation building 1. Without using texture. In this case colors of nodes are specified with DataMapOfIntegerColor and presentation is built with gradient fill between these nodes (default behaviour) 2. Using texture. In this case presentation is built with spectrum filling between nodes. For example, if one node has blue color and second one has violet color, parameters of this class may be set to fill presentation between nodes with solar spectrum. Methods: UseTexture - activates/deactivates this way SetColorMap - sets colors used for generation of texture SetColorindices - specifies correspondence between node IDs and indices of colors from color map");
	cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &>(), py::arg("Parent"));
	cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Flags"));
	cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"));
	cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
	cls_MeshVS_NodalColorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
	cls_MeshVS_NodalColorPrsBuilder.def("Build", (void (MeshVS_NodalColorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_NodalColorPrsBuilder::Build, "Builds presentation of nodes with assigned color.", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("DisplayMode"));
	cls_MeshVS_NodalColorPrsBuilder.def("GetColors", (const MeshVS_DataMapOfIntegerColor & (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::GetColors, "Returns map of colors assigned to nodes.");
	cls_MeshVS_NodalColorPrsBuilder.def("SetColors", (void (MeshVS_NodalColorPrsBuilder::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_NodalColorPrsBuilder::SetColors, "Sets map of colors assigned to nodes.", py::arg("Map"));
	cls_MeshVS_NodalColorPrsBuilder.def("HasColors", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::HasColors, "Returns true, if map isn't empty");
	cls_MeshVS_NodalColorPrsBuilder.def("GetColor", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, Quantity_Color &) const ) &MeshVS_NodalColorPrsBuilder::GetColor, "Returns color assigned to single node", py::arg("ID"), py::arg("theColor"));
	cls_MeshVS_NodalColorPrsBuilder.def("SetColor", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, const Quantity_Color &)) &MeshVS_NodalColorPrsBuilder::SetColor, "Sets color assigned to single node", py::arg("ID"), py::arg("theColor"));
	cls_MeshVS_NodalColorPrsBuilder.def("UseTexture", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Boolean)) &MeshVS_NodalColorPrsBuilder::UseTexture, "Specify whether texture must be used to build presentation", py::arg("theToUse"));
	cls_MeshVS_NodalColorPrsBuilder.def("IsUseTexture", (Standard_Boolean (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::IsUseTexture, "Verify whether texture is used to build presentation");
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("SetColorMap", (void (MeshVS_NodalColorPrsBuilder::*)(const Aspect_SequenceOfColor &)) &MeshVS_NodalColorPrsBuilder::SetColorMap, "Set colors to be used for texrture presentation theColors - colors for valid coordinates (laying in range [0, 1])", py::arg("theColors"));
	cls_MeshVS_NodalColorPrsBuilder.def("GetColorMap", (const Aspect_SequenceOfColor & (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::GetColorMap, "Return colors used for texrture presentation");
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("SetInvalidColor", (void (MeshVS_NodalColorPrsBuilder::*)(const Quantity_Color &)) &MeshVS_NodalColorPrsBuilder::SetInvalidColor, "Set color representing invalid texture coordinate (laying outside range [0, 1])", py::arg("theInvalidColor"));
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("GetInvalidColor", (Quantity_Color (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::GetInvalidColor, "Return color representing invalid texture coordinate (laying outside range [0, 1])");
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("SetTextureCoords", (void (MeshVS_NodalColorPrsBuilder::*)(const TColStd_DataMapOfIntegerReal &)) &MeshVS_NodalColorPrsBuilder::SetTextureCoords, "Specify correspondence between node IDs and texture coordinates (range [0, 1])", py::arg("theMap"));
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("GetTextureCoords", (const TColStd_DataMapOfIntegerReal & (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::GetTextureCoords, "Get correspondence between node IDs and texture coordinates (range [0, 1])");
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("SetTextureCoord", (void (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer, const Standard_Real)) &MeshVS_NodalColorPrsBuilder::SetTextureCoord, "Specify correspondence between node ID and texture coordinate (range [0, 1])", py::arg("theID"), py::arg("theCoord"));
	// FIXME cls_MeshVS_NodalColorPrsBuilder.def("GetTextureCoord", (Standard_Real (MeshVS_NodalColorPrsBuilder::*)(const Standard_Integer)) &MeshVS_NodalColorPrsBuilder::GetTextureCoord, "Return correspondence between node IDs and texture coordinate (range [0, 1])", py::arg("theID"));
	cls_MeshVS_NodalColorPrsBuilder.def("AddVolumePrs", (void (MeshVS_NodalColorPrsBuilder::*)(const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &, const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Real) const ) &MeshVS_NodalColorPrsBuilder::AddVolumePrs, "Add to array polygons or polylines representing volume", py::arg("theTopo"), py::arg("theNodes"), py::arg("theCoords"), py::arg("theArray"), py::arg("theIsShaded"), py::arg("theNbColors"), py::arg("theNbTexColors"), py::arg("theColorRatio"));
	cls_MeshVS_NodalColorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_NodalColorPrsBuilder::get_type_name, "None");
	cls_MeshVS_NodalColorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_NodalColorPrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_NodalColorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_NodalColorPrsBuilder::*)() const ) &MeshVS_NodalColorPrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitiveFace.hxx
	py::class_<MeshVS_SensitiveFace, opencascade::handle<MeshVS_SensitiveFace>, Select3D_SensitiveFace> cls_MeshVS_SensitiveFace(mod, "MeshVS_SensitiveFace", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");
	cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("thePoints"));
	cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwner"), py::arg("thePoints"), py::arg("theSensType"));
	cls_MeshVS_SensitiveFace.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveFace::get_type_name, "None");
	cls_MeshVS_SensitiveFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveFace::get_type_descriptor, "None");
	cls_MeshVS_SensitiveFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveFace::*)() const ) &MeshVS_SensitiveFace::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitiveMesh.hxx
	py::class_<MeshVS_SensitiveMesh, opencascade::handle<MeshVS_SensitiveMesh>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveMesh(mod, "MeshVS_SensitiveMesh", "This class provides custom mesh sensitive entity used in advanced mesh selection.");
	cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwner"));
	cls_MeshVS_SensitiveMesh.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Integer>(), py::arg("theOwner"), py::arg("theMode"));
	cls_MeshVS_SensitiveMesh.def("GetMode", (Standard_Integer (MeshVS_SensitiveMesh::*)() const ) &MeshVS_SensitiveMesh::GetMode, "None");
	cls_MeshVS_SensitiveMesh.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::GetConnected, "None");
	cls_MeshVS_SensitiveMesh.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::NbSubElements, "Returns the amount of mesh nodes");
	cls_MeshVS_SensitiveMesh.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveMesh::*)()) &MeshVS_SensitiveMesh::BoundingBox, "Returns bounding box of mesh");
	cls_MeshVS_SensitiveMesh.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveMesh::*)() const ) &MeshVS_SensitiveMesh::CenterOfGeometry, "Returns center of mesh");
	cls_MeshVS_SensitiveMesh.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveMesh::get_type_name, "None");
	cls_MeshVS_SensitiveMesh.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveMesh::get_type_descriptor, "None");
	cls_MeshVS_SensitiveMesh.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveMesh::*)() const ) &MeshVS_SensitiveMesh::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitivePolyhedron.hxx
	py::class_<SelectBasics_ListOfBox2d, std::unique_ptr<SelectBasics_ListOfBox2d, Deleter<SelectBasics_ListOfBox2d>>> cls_SelectBasics_ListOfBox2d(mod, "SelectBasics_ListOfBox2d", "None");
	cls_SelectBasics_ListOfBox2d.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitivePolyhedron.hxx
	py::class_<MeshVS_SensitivePolyhedron, opencascade::handle<MeshVS_SensitivePolyhedron>, Select3D_SensitiveEntity> cls_MeshVS_SensitivePolyhedron(mod, "MeshVS_SensitivePolyhedron", "This class is used to detect selection of a polyhedron. The main principle of detection algorithm is to search for overlap with each polyhedron's face separately, treating them as planar convex polygons.");
	cls_MeshVS_SensitivePolyhedron.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &>(), py::arg("theOwner"), py::arg("theNodes"), py::arg("theTopo"));
	cls_MeshVS_SensitivePolyhedron.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::GetConnected, "None");
	cls_MeshVS_SensitivePolyhedron.def("Matches", (Standard_Boolean (MeshVS_SensitivePolyhedron::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitivePolyhedron::Matches, "None", py::arg("theMgr"), py::arg("thePickResult"));
	cls_MeshVS_SensitivePolyhedron.def("NbSubElements", (Standard_Integer (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::NbSubElements, "Returns the amount of nodes of polyhedron");
	cls_MeshVS_SensitivePolyhedron.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitivePolyhedron::*)()) &MeshVS_SensitivePolyhedron::BoundingBox, "None");
	cls_MeshVS_SensitivePolyhedron.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitivePolyhedron::*)() const ) &MeshVS_SensitivePolyhedron::CenterOfGeometry, "None");
	cls_MeshVS_SensitivePolyhedron.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitivePolyhedron::get_type_name, "None");
	cls_MeshVS_SensitivePolyhedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitivePolyhedron::get_type_descriptor, "None");
	cls_MeshVS_SensitivePolyhedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitivePolyhedron::*)() const ) &MeshVS_SensitivePolyhedron::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitiveQuad.hxx
	py::class_<MeshVS_SensitiveQuad, opencascade::handle<MeshVS_SensitiveQuad>, Select3D_SensitiveEntity> cls_MeshVS_SensitiveQuad(mod, "MeshVS_SensitiveQuad", "This class contains description of planar quadrangle and defines methods for its detection by OCCT BVH selection mechanism");
	cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("theQuadVerts"));
	cls_MeshVS_SensitiveQuad.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("thePnt4"));
	cls_MeshVS_SensitiveQuad.def("NbSubElements", (Standard_Integer (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::NbSubElements, "Returns the amount of sub-entities in sensitive");
	cls_MeshVS_SensitiveQuad.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::GetConnected, "Returns a copy of this sensitive quadrangle");
	cls_MeshVS_SensitiveQuad.def("Matches", (Standard_Boolean (MeshVS_SensitiveQuad::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &MeshVS_SensitiveQuad::Matches, "Checks whether the box overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_MeshVS_SensitiveQuad.def("CenterOfGeometry", (gp_Pnt (MeshVS_SensitiveQuad::*)() const ) &MeshVS_SensitiveQuad::CenterOfGeometry, "Returns center of the box");
	cls_MeshVS_SensitiveQuad.def("BoundingBox", (Select3D_BndBox3d (MeshVS_SensitiveQuad::*)()) &MeshVS_SensitiveQuad::BoundingBox, "Returns coordinates of the box");
	cls_MeshVS_SensitiveQuad.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveQuad::get_type_name, "None");
	cls_MeshVS_SensitiveQuad.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveQuad::get_type_descriptor, "None");
	cls_MeshVS_SensitiveQuad.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveQuad::*)() const ) &MeshVS_SensitiveQuad::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SensitiveSegment.hxx
	py::class_<MeshVS_SensitiveSegment, opencascade::handle<MeshVS_SensitiveSegment>, Select3D_SensitiveSegment> cls_MeshVS_SensitiveSegment(mod, "MeshVS_SensitiveSegment", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");
	cls_MeshVS_SensitiveSegment.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
	cls_MeshVS_SensitiveSegment.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveSegment::get_type_name, "None");
	cls_MeshVS_SensitiveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveSegment::get_type_descriptor, "None");
	cls_MeshVS_SensitiveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveSegment::*)() const ) &MeshVS_SensitiveSegment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SymmetricPairHasher.hxx
	py::class_<MeshVS_SymmetricPairHasher, std::unique_ptr<MeshVS_SymmetricPairHasher, Deleter<MeshVS_SymmetricPairHasher>>> cls_MeshVS_SymmetricPairHasher(mod, "MeshVS_SymmetricPairHasher", "Provides symmetric hash methods pair of integers.");
	cls_MeshVS_SymmetricPairHasher.def(py::init<>());
	cls_MeshVS_SymmetricPairHasher.def_static("HashCode_", (Standard_Integer (*)(const MeshVS_NodePair &, const Standard_Integer)) &MeshVS_SymmetricPairHasher::HashCode, "None", py::arg("thePair"), py::arg("theMaxCode"));
	cls_MeshVS_SymmetricPairHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MeshVS_NodePair &, const MeshVS_NodePair &)) &MeshVS_SymmetricPairHasher::IsEqual, "None", py::arg("thePair1"), py::arg("thePair2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TextPrsBuilder.hxx
	py::class_<MeshVS_TextPrsBuilder, opencascade::handle<MeshVS_TextPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_TextPrsBuilder(mod, "MeshVS_TextPrsBuilder", "This class provides methods to create text data presentation. It store map of texts assigned with nodes or elements.");
	cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"));
	cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"));
	cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"));
	cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
	cls_MeshVS_TextPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("Height"), py::arg("Color"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
	cls_MeshVS_TextPrsBuilder.def("Build", (void (MeshVS_TextPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_TextPrsBuilder::Build, "Builds presentation of text data", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("theDisplayMode"));
	cls_MeshVS_TextPrsBuilder.def("GetTexts", (const MeshVS_DataMapOfIntegerAsciiString & (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const ) &MeshVS_TextPrsBuilder::GetTexts, "Returns map of text assigned with nodes ( IsElement = False ) or elements ( IsElement = True )", py::arg("IsElement"));
	cls_MeshVS_TextPrsBuilder.def("SetTexts", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_TextPrsBuilder::SetTexts, "Sets map of text assigned with nodes or elements", py::arg("IsElement"), py::arg("Map"));
	cls_MeshVS_TextPrsBuilder.def("HasTexts", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean) const ) &MeshVS_TextPrsBuilder::HasTexts, "Returns True if map isn't empty", py::arg("IsElement"));
	cls_MeshVS_TextPrsBuilder.def("GetText", (Standard_Boolean (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, TCollection_AsciiString &) const ) &MeshVS_TextPrsBuilder::GetText, "Returns text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
	cls_MeshVS_TextPrsBuilder.def("SetText", (void (MeshVS_TextPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, const TCollection_AsciiString &)) &MeshVS_TextPrsBuilder::SetText, "Sets text assigned with single node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Text"));
	cls_MeshVS_TextPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_TextPrsBuilder::get_type_name, "None");
	cls_MeshVS_TextPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_TextPrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_TextPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_TextPrsBuilder::*)() const ) &MeshVS_TextPrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_Tool.hxx
	py::class_<MeshVS_Tool, std::unique_ptr<MeshVS_Tool, Deleter<MeshVS_Tool>>> cls_MeshVS_Tool(mod, "MeshVS_Tool", "This class provides auxiliary methods to create differents aspects");
	cls_MeshVS_Tool.def(py::init<>());
	cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectFillArea3d> { return MeshVS_Tool::CreateAspectFillArea3d(a0); }, py::arg("theDr"));
	cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", (opencascade::handle<Graphic3d_AspectFillArea3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectFillArea3d, "Creates fill area aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
	cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", [](const opencascade::handle<MeshVS_Drawer> & a0, const Graphic3d_MaterialAspect & a1) -> opencascade::handle<Graphic3d_AspectFillArea3d> { return MeshVS_Tool::CreateAspectFillArea3d(a0, a1); }, py::arg("theDr"), py::arg("Mat"));
	cls_MeshVS_Tool.def_static("CreateAspectFillArea3d_", (opencascade::handle<Graphic3d_AspectFillArea3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Graphic3d_MaterialAspect &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectFillArea3d, "Creates fill aspect with values from Drawer according to keys from DrawerAttribute and specific material aspect", py::arg("theDr"), py::arg("Mat"), py::arg("UseDefaults"));
	cls_MeshVS_Tool.def_static("CreateAspectLine3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectLine3d> { return MeshVS_Tool::CreateAspectLine3d(a0); }, py::arg("theDr"));
	cls_MeshVS_Tool.def_static("CreateAspectLine3d_", (opencascade::handle<Graphic3d_AspectLine3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectLine3d, "Creates line aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
	cls_MeshVS_Tool.def_static("CreateAspectMarker3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectMarker3d> { return MeshVS_Tool::CreateAspectMarker3d(a0); }, py::arg("theDr"));
	cls_MeshVS_Tool.def_static("CreateAspectMarker3d_", (opencascade::handle<Graphic3d_AspectMarker3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectMarker3d, "Creates marker aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
	cls_MeshVS_Tool.def_static("CreateAspectText3d_", [](const opencascade::handle<MeshVS_Drawer> & a0) -> opencascade::handle<Graphic3d_AspectText3d> { return MeshVS_Tool::CreateAspectText3d(a0); }, py::arg("theDr"));
	cls_MeshVS_Tool.def_static("CreateAspectText3d_", (opencascade::handle<Graphic3d_AspectText3d> (*)(const opencascade::handle<MeshVS_Drawer> &, const Standard_Boolean)) &MeshVS_Tool::CreateAspectText3d, "Creates text aspect with values from Drawer according to keys from DrawerAttribute", py::arg("theDr"), py::arg("UseDefaults"));
	cls_MeshVS_Tool.def_static("GetNormal_", (Standard_Boolean (*)(const TColStd_Array1OfReal &, gp_Vec &)) &MeshVS_Tool::GetNormal, "Get one of normals to polygon described by these points. If the polygon isn't planar, function returns false", py::arg("Nodes"), py::arg("Norm"));
	cls_MeshVS_Tool.def_static("GetAverageNormal_", (Standard_Boolean (*)(const TColStd_Array1OfReal &, gp_Vec &)) &MeshVS_Tool::GetAverageNormal, "Get an average of normals to non-planar polygon described by these points or compute normal of planar polygon. If the polygon isn't planar, function returns false", py::arg("Nodes"), py::arg("Norm"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_VectorPrsBuilder.hxx
	py::class_<MeshVS_VectorPrsBuilder, opencascade::handle<MeshVS_VectorPrsBuilder>, MeshVS_PrsBuilder> cls_MeshVS_VectorPrsBuilder(mod, "MeshVS_VectorPrsBuilder", "This class provides methods to create vector data presentation. It store map of vectors assigned with nodes or elements. In simplified mode vectors draws with thickened ends instead of arrows");
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"));
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"));
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"));
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"));
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"));
	cls_MeshVS_VectorPrsBuilder.def(py::init<const opencascade::handle<MeshVS_Mesh> &, const Standard_Real, const Quantity_Color &, const MeshVS_DisplayModeFlags &, const opencascade::handle<MeshVS_DataSource> &, const Standard_Integer, const MeshVS_BuilderPriority &, const Standard_Boolean>(), py::arg("Parent"), py::arg("MaxLength"), py::arg("VectorColor"), py::arg("Flags"), py::arg("DS"), py::arg("Id"), py::arg("Priority"), py::arg("IsSimplePrs"));
	cls_MeshVS_VectorPrsBuilder.def("Build", (void (MeshVS_VectorPrsBuilder::*)(const opencascade::handle<Prs3d_Presentation> &, const TColStd_PackedMapOfInteger &, TColStd_PackedMapOfInteger &, const Standard_Boolean, const Standard_Integer) const ) &MeshVS_VectorPrsBuilder::Build, "Builds vector data presentation", py::arg("Prs"), py::arg("IDs"), py::arg("IDsToExclude"), py::arg("IsElement"), py::arg("theDisplayMode"));
	cls_MeshVS_VectorPrsBuilder.def("DrawVector", (void (MeshVS_VectorPrsBuilder::*)(const gp_Trsf &, const Standard_Real, const Standard_Real, const TColgp_Array1OfPnt &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &, const opencascade::handle<Graphic3d_ArrayOfPrimitives> &) const ) &MeshVS_VectorPrsBuilder::DrawVector, "Adds to array of polygons and polylines some primitive representing single vector", py::arg("theTrsf"), py::arg("Length"), py::arg("MaxLength"), py::arg("ArrowPoints"), py::arg("Lines"), py::arg("ArrowLines"), py::arg("Triangles"));
	cls_MeshVS_VectorPrsBuilder.def_static("calculateArrow_", (Standard_Real (*)(TColgp_Array1OfPnt &, const Standard_Real, const Standard_Real)) &MeshVS_VectorPrsBuilder::calculateArrow, "Calculates points of arrow presentation", py::arg("Points"), py::arg("Length"), py::arg("ArrowPart"));
	cls_MeshVS_VectorPrsBuilder.def("GetVectors", (const MeshVS_DataMapOfIntegerVector & (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean) const ) &MeshVS_VectorPrsBuilder::GetVectors, "Returns map of vectors assigned with nodes or elements", py::arg("IsElement"));
	cls_MeshVS_VectorPrsBuilder.def("SetVectors", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const MeshVS_DataMapOfIntegerVector &)) &MeshVS_VectorPrsBuilder::SetVectors, "Sets map of vectors assigned with nodes or elements", py::arg("IsElement"), py::arg("Map"));
	cls_MeshVS_VectorPrsBuilder.def("HasVectors", (Standard_Boolean (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean) const ) &MeshVS_VectorPrsBuilder::HasVectors, "Returns true, if map isn't empty", py::arg("IsElement"));
	cls_MeshVS_VectorPrsBuilder.def("GetVector", (Standard_Boolean (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, gp_Vec &) const ) &MeshVS_VectorPrsBuilder::GetVector, "Returns vector assigned with certain node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Vect"));
	cls_MeshVS_VectorPrsBuilder.def("SetVector", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, const Standard_Integer, const gp_Vec &)) &MeshVS_VectorPrsBuilder::SetVector, "Sets vector assigned with certain node or element", py::arg("IsElement"), py::arg("ID"), py::arg("Vect"));
	cls_MeshVS_VectorPrsBuilder.def("GetMinMaxVectorValue", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean, Standard_Real &, Standard_Real &) const ) &MeshVS_VectorPrsBuilder::GetMinMaxVectorValue, "Calculates minimal and maximal length of vectors in map ( nodal, if IsElement = False or elemental, if IsElement = True )", py::arg("IsElement"), py::arg("MinValue"), py::arg("MaxValue"));
	cls_MeshVS_VectorPrsBuilder.def("SetSimplePrsMode", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Boolean)) &MeshVS_VectorPrsBuilder::SetSimplePrsMode, "Sets flag that indicates is simple vector arrow mode uses or not default value is False", py::arg("IsSimpleArrow"));
	cls_MeshVS_VectorPrsBuilder.def("SetSimplePrsParams", (void (MeshVS_VectorPrsBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &MeshVS_VectorPrsBuilder::SetSimplePrsParams, "Sets parameters of simple vector arrwo presentation theLineWidthParam - coefficient of vector line width (to draw line instead of arrow) theStartParam and theEndParam parameters of start and end of thickened ends position of thickening calculates according to parameters and maximum vector length default values are: theLineWidthParam = 2.5 theStartParam = 0.85 theEndParam = 0.95", py::arg("theLineWidthParam"), py::arg("theStartParam"), py::arg("theEndParam"));
	cls_MeshVS_VectorPrsBuilder.def_static("get_type_name_", (const char * (*)()) &MeshVS_VectorPrsBuilder::get_type_name, "None");
	cls_MeshVS_VectorPrsBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_VectorPrsBuilder::get_type_descriptor, "None");
	cls_MeshVS_VectorPrsBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_VectorPrsBuilder::*)() const ) &MeshVS_VectorPrsBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_HArray1OfSequenceOfInteger.hxx
	py::class_<MeshVS_HArray1OfSequenceOfInteger, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger>, MeshVS_Array1OfSequenceOfInteger, Standard_Transient> cls_MeshVS_HArray1OfSequenceOfInteger(mod, "MeshVS_HArray1OfSequenceOfInteger", "None");
	cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const Standard_Integer, const Standard_Integer, const MeshVS_Array1OfSequenceOfInteger::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_MeshVS_HArray1OfSequenceOfInteger.def(py::init<const MeshVS_Array1OfSequenceOfInteger &>(), py::arg("theOther"));
	cls_MeshVS_HArray1OfSequenceOfInteger.def("Array1", (const MeshVS_Array1OfSequenceOfInteger & (MeshVS_HArray1OfSequenceOfInteger::*)() const ) &MeshVS_HArray1OfSequenceOfInteger::Array1, "None");
	cls_MeshVS_HArray1OfSequenceOfInteger.def("ChangeArray1", (MeshVS_Array1OfSequenceOfInteger & (MeshVS_HArray1OfSequenceOfInteger::*)()) &MeshVS_HArray1OfSequenceOfInteger::ChangeArray1, "None");
	cls_MeshVS_HArray1OfSequenceOfInteger.def_static("get_type_name_", (const char * (*)()) &MeshVS_HArray1OfSequenceOfInteger::get_type_name, "None");
	cls_MeshVS_HArray1OfSequenceOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_HArray1OfSequenceOfInteger::get_type_descriptor, "None");
	cls_MeshVS_HArray1OfSequenceOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_HArray1OfSequenceOfInteger::*)() const ) &MeshVS_HArray1OfSequenceOfInteger::DynamicType, "None");

	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "integer")) {
		mod.attr("MeshVS_BuilderPriority") = other_mod.attr("integer");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_ColorHasher.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_EntityType.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MeshPtr.hxx
	other_mod = py::module::import("OCCT.AdvApp2Var");
	if (py::hasattr(other_mod, "integer")) {
		mod.attr("MeshVS_DisplayModeFlags") = other_mod.attr("integer");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<MeshVS_SequenceOfPrsBuilder, std::unique_ptr<MeshVS_SequenceOfPrsBuilder, Deleter<MeshVS_SequenceOfPrsBuilder>>, NCollection_BaseSequence> cls_MeshVS_SequenceOfPrsBuilder(mod, "MeshVS_SequenceOfPrsBuilder", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_MeshVS_SequenceOfPrsBuilder.def(py::init<>());
	cls_MeshVS_SequenceOfPrsBuilder.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MeshVS_SequenceOfPrsBuilder.def(py::init([] (const MeshVS_SequenceOfPrsBuilder &other) {return new MeshVS_SequenceOfPrsBuilder(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_SequenceOfPrsBuilder.def("begin", (MeshVS_SequenceOfPrsBuilder::iterator (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_MeshVS_SequenceOfPrsBuilder.def("end", (MeshVS_SequenceOfPrsBuilder::iterator (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_MeshVS_SequenceOfPrsBuilder.def("cbegin", (MeshVS_SequenceOfPrsBuilder::const_iterator (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_MeshVS_SequenceOfPrsBuilder.def("cend", (MeshVS_SequenceOfPrsBuilder::const_iterator (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_MeshVS_SequenceOfPrsBuilder.def("Size", (Standard_Integer (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::Size, "Number of items");
	cls_MeshVS_SequenceOfPrsBuilder.def("Length", (Standard_Integer (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::Length, "Number of items");
	cls_MeshVS_SequenceOfPrsBuilder.def("Lower", (Standard_Integer (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::Lower, "Method for consistency with other collections.");
	cls_MeshVS_SequenceOfPrsBuilder.def("Upper", (Standard_Integer (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::Upper, "Method for consistency with other collections.");
	cls_MeshVS_SequenceOfPrsBuilder.def("IsEmpty", (Standard_Boolean (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::IsEmpty, "Empty query");
	cls_MeshVS_SequenceOfPrsBuilder.def("Reverse", (void (MeshVS_SequenceOfPrsBuilder::*)()) &MeshVS_SequenceOfPrsBuilder::Reverse, "Reverse sequence");
	cls_MeshVS_SequenceOfPrsBuilder.def("Exchange", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_SequenceOfPrsBuilder::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_MeshVS_SequenceOfPrsBuilder.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_SequenceOfPrsBuilder::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Clear", [](MeshVS_SequenceOfPrsBuilder &self) -> void { return self.Clear(); });
	cls_MeshVS_SequenceOfPrsBuilder.def("Clear", (void (MeshVS_SequenceOfPrsBuilder::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_SequenceOfPrsBuilder::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Assign", (MeshVS_SequenceOfPrsBuilder & (MeshVS_SequenceOfPrsBuilder::*)(const MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_SequenceOfPrsBuilder.def("assign", (MeshVS_SequenceOfPrsBuilder & (MeshVS_SequenceOfPrsBuilder::*)(const MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Remove", (void (MeshVS_SequenceOfPrsBuilder::*)(MeshVS_SequenceOfPrsBuilder::Iterator &)) &MeshVS_SequenceOfPrsBuilder::Remove, "Remove one item", py::arg("thePosition"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Remove", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer)) &MeshVS_SequenceOfPrsBuilder::Remove, "Remove one item", py::arg("theIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Remove", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, const Standard_Integer)) &MeshVS_SequenceOfPrsBuilder::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Append", (void (MeshVS_SequenceOfPrsBuilder::*)(const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::Append, "Append one item", py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Append", (void (MeshVS_SequenceOfPrsBuilder::*)(MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Prepend", (void (MeshVS_SequenceOfPrsBuilder::*)(const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::Prepend, "Prepend one item", py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Prepend", (void (MeshVS_SequenceOfPrsBuilder::*)(MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_MeshVS_SequenceOfPrsBuilder.def("InsertBefore", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("InsertBefore", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_MeshVS_SequenceOfPrsBuilder.def("InsertAfter", (void (MeshVS_SequenceOfPrsBuilder::*)(MeshVS_SequenceOfPrsBuilder::Iterator &, const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("InsertAfter", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_MeshVS_SequenceOfPrsBuilder.def("InsertAfter", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("Split", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, MeshVS_SequenceOfPrsBuilder &)) &MeshVS_SequenceOfPrsBuilder::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_MeshVS_SequenceOfPrsBuilder.def("First", (const opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::First, "First item access");
	cls_MeshVS_SequenceOfPrsBuilder.def("ChangeFirst", (opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)()) &MeshVS_SequenceOfPrsBuilder::ChangeFirst, "First item access");
	cls_MeshVS_SequenceOfPrsBuilder.def("Last", (const opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)() const ) &MeshVS_SequenceOfPrsBuilder::Last, "Last item access");
	cls_MeshVS_SequenceOfPrsBuilder.def("ChangeLast", (opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)()) &MeshVS_SequenceOfPrsBuilder::ChangeLast, "Last item access");
	cls_MeshVS_SequenceOfPrsBuilder.def("Value", (const opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer) const ) &MeshVS_SequenceOfPrsBuilder::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("__call__", (const opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer) const ) &MeshVS_SequenceOfPrsBuilder::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("ChangeValue", (opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer)) &MeshVS_SequenceOfPrsBuilder::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("__call__", (opencascade::handle<MeshVS_PrsBuilder> & (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer)) &MeshVS_SequenceOfPrsBuilder::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_MeshVS_SequenceOfPrsBuilder.def("SetValue", (void (MeshVS_SequenceOfPrsBuilder::*)(const Standard_Integer, const opencascade::handle<MeshVS_PrsBuilder> &)) &MeshVS_SequenceOfPrsBuilder::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_MeshVS_SequenceOfPrsBuilder.def("__iter__", [](const MeshVS_SequenceOfPrsBuilder &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerOwner, std::unique_ptr<MeshVS_DataMapOfIntegerOwner, Deleter<MeshVS_DataMapOfIntegerOwner>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerOwner(mod, "MeshVS_DataMapOfIntegerOwner", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerOwner.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerOwner.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerOwner.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerOwner.def(py::init([] (const MeshVS_DataMapOfIntegerOwner &other) {return new MeshVS_DataMapOfIntegerOwner(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerOwner.def("begin", (MeshVS_DataMapOfIntegerOwner::iterator (MeshVS_DataMapOfIntegerOwner::*)() const ) &MeshVS_DataMapOfIntegerOwner::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerOwner.def("end", (MeshVS_DataMapOfIntegerOwner::iterator (MeshVS_DataMapOfIntegerOwner::*)() const ) &MeshVS_DataMapOfIntegerOwner::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerOwner.def("cbegin", (MeshVS_DataMapOfIntegerOwner::const_iterator (MeshVS_DataMapOfIntegerOwner::*)() const ) &MeshVS_DataMapOfIntegerOwner::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerOwner.def("cend", (MeshVS_DataMapOfIntegerOwner::const_iterator (MeshVS_DataMapOfIntegerOwner::*)() const ) &MeshVS_DataMapOfIntegerOwner::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerOwner.def("Exchange", (void (MeshVS_DataMapOfIntegerOwner::*)(MeshVS_DataMapOfIntegerOwner &)) &MeshVS_DataMapOfIntegerOwner::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerOwner.def("Assign", (MeshVS_DataMapOfIntegerOwner & (MeshVS_DataMapOfIntegerOwner::*)(const MeshVS_DataMapOfIntegerOwner &)) &MeshVS_DataMapOfIntegerOwner::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerOwner.def("assign", (MeshVS_DataMapOfIntegerOwner & (MeshVS_DataMapOfIntegerOwner::*)(const MeshVS_DataMapOfIntegerOwner &)) &MeshVS_DataMapOfIntegerOwner::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerOwner.def("ReSize", (void (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerOwner::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerOwner.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &, const opencascade::handle<SelectMgr_EntityOwner> &)) &MeshVS_DataMapOfIntegerOwner::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerOwner.def("Bound", (opencascade::handle<SelectMgr_EntityOwner> * (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &, const opencascade::handle<SelectMgr_EntityOwner> &)) &MeshVS_DataMapOfIntegerOwner::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerOwner.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerOwner::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerOwner.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerOwner::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerOwner.def("Seek", (const opencascade::handle<SelectMgr_EntityOwner> * (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerOwner::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerOwner.def("Find", (const opencascade::handle<SelectMgr_EntityOwner> & (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerOwner::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerOwner.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &, opencascade::handle<SelectMgr_EntityOwner> &) const ) &MeshVS_DataMapOfIntegerOwner::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerOwner.def("__call__", (const opencascade::handle<SelectMgr_EntityOwner> & (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerOwner::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerOwner.def("ChangeSeek", (opencascade::handle<SelectMgr_EntityOwner> * (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerOwner::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerOwner.def("ChangeFind", (opencascade::handle<SelectMgr_EntityOwner> & (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerOwner::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerOwner.def("__call__", (opencascade::handle<SelectMgr_EntityOwner> & (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerOwner::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerOwner.def("Clear", [](MeshVS_DataMapOfIntegerOwner &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerOwner.def("Clear", (void (MeshVS_DataMapOfIntegerOwner::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerOwner::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerOwner.def("Clear", (void (MeshVS_DataMapOfIntegerOwner::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerOwner::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerOwner.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerOwner::*)() const ) &MeshVS_DataMapOfIntegerOwner::Size, "Size");
	cls_MeshVS_DataMapOfIntegerOwner.def("__iter__", [](const MeshVS_DataMapOfIntegerOwner &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerOwner.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfColorMapOfInteger, std::unique_ptr<MeshVS_DataMapOfColorMapOfInteger, Deleter<MeshVS_DataMapOfColorMapOfInteger>>, NCollection_BaseMap> cls_MeshVS_DataMapOfColorMapOfInteger(mod, "MeshVS_DataMapOfColorMapOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfColorMapOfInteger.def(py::init<>());
	cls_MeshVS_DataMapOfColorMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def(py::init([] (const MeshVS_DataMapOfColorMapOfInteger &other) {return new MeshVS_DataMapOfColorMapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("begin", (MeshVS_DataMapOfColorMapOfInteger::iterator (MeshVS_DataMapOfColorMapOfInteger::*)() const ) &MeshVS_DataMapOfColorMapOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfColorMapOfInteger.def("end", (MeshVS_DataMapOfColorMapOfInteger::iterator (MeshVS_DataMapOfColorMapOfInteger::*)() const ) &MeshVS_DataMapOfColorMapOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfColorMapOfInteger.def("cbegin", (MeshVS_DataMapOfColorMapOfInteger::const_iterator (MeshVS_DataMapOfColorMapOfInteger::*)() const ) &MeshVS_DataMapOfColorMapOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfColorMapOfInteger.def("cend", (MeshVS_DataMapOfColorMapOfInteger::const_iterator (MeshVS_DataMapOfColorMapOfInteger::*)() const ) &MeshVS_DataMapOfColorMapOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Exchange", (void (MeshVS_DataMapOfColorMapOfInteger::*)(MeshVS_DataMapOfColorMapOfInteger &)) &MeshVS_DataMapOfColorMapOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Assign", (MeshVS_DataMapOfColorMapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const MeshVS_DataMapOfColorMapOfInteger &)) &MeshVS_DataMapOfColorMapOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("assign", (MeshVS_DataMapOfColorMapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const MeshVS_DataMapOfColorMapOfInteger &)) &MeshVS_DataMapOfColorMapOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("ReSize", (void (MeshVS_DataMapOfColorMapOfInteger::*)(const Standard_Integer)) &MeshVS_DataMapOfColorMapOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Bind", (Standard_Boolean (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &, const TColStd_MapOfInteger &)) &MeshVS_DataMapOfColorMapOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfColorMapOfInteger.def("Bound", (TColStd_MapOfInteger * (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &, const TColStd_MapOfInteger &)) &MeshVS_DataMapOfColorMapOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &) const ) &MeshVS_DataMapOfColorMapOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &)) &MeshVS_DataMapOfColorMapOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfColorMapOfInteger.def("Seek", (const TColStd_MapOfInteger * (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &) const ) &MeshVS_DataMapOfColorMapOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfColorMapOfInteger.def("Find", (const TColStd_MapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &) const ) &MeshVS_DataMapOfColorMapOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfColorMapOfInteger.def("Find", (Standard_Boolean (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &, TColStd_MapOfInteger &) const ) &MeshVS_DataMapOfColorMapOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("__call__", (const TColStd_MapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &) const ) &MeshVS_DataMapOfColorMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfColorMapOfInteger.def("ChangeSeek", (TColStd_MapOfInteger * (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &)) &MeshVS_DataMapOfColorMapOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("ChangeFind", (TColStd_MapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &)) &MeshVS_DataMapOfColorMapOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("__call__", (TColStd_MapOfInteger & (MeshVS_DataMapOfColorMapOfInteger::*)(const Quantity_Color &)) &MeshVS_DataMapOfColorMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Clear", [](MeshVS_DataMapOfColorMapOfInteger &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Clear", (void (MeshVS_DataMapOfColorMapOfInteger::*)(const Standard_Boolean)) &MeshVS_DataMapOfColorMapOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Clear", (void (MeshVS_DataMapOfColorMapOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfColorMapOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfColorMapOfInteger.def("Size", (Standard_Integer (MeshVS_DataMapOfColorMapOfInteger::*)() const ) &MeshVS_DataMapOfColorMapOfInteger::Size, "Size");
	cls_MeshVS_DataMapOfColorMapOfInteger.def("__iter__", [](const MeshVS_DataMapOfColorMapOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfColorMapOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfHArray1OfSequenceOfInteger, std::unique_ptr<MeshVS_DataMapOfHArray1OfSequenceOfInteger, Deleter<MeshVS_DataMapOfHArray1OfSequenceOfInteger>>, NCollection_BaseMap> cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger(mod, "MeshVS_DataMapOfHArray1OfSequenceOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def(py::init<>());
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def(py::init([] (const MeshVS_DataMapOfHArray1OfSequenceOfInteger &other) {return new MeshVS_DataMapOfHArray1OfSequenceOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("begin", (MeshVS_DataMapOfHArray1OfSequenceOfInteger::iterator (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)() const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("end", (MeshVS_DataMapOfHArray1OfSequenceOfInteger::iterator (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)() const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("cbegin", (MeshVS_DataMapOfHArray1OfSequenceOfInteger::const_iterator (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)() const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("cend", (MeshVS_DataMapOfHArray1OfSequenceOfInteger::const_iterator (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)() const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Exchange", (void (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(MeshVS_DataMapOfHArray1OfSequenceOfInteger &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Assign", (MeshVS_DataMapOfHArray1OfSequenceOfInteger & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const MeshVS_DataMapOfHArray1OfSequenceOfInteger &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("assign", (MeshVS_DataMapOfHArray1OfSequenceOfInteger & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const MeshVS_DataMapOfHArray1OfSequenceOfInteger &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("ReSize", (void (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Bind", (Standard_Boolean (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &, const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Bound", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> * (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &, const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Seek", (const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> * (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Find", (const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Find", (Standard_Boolean (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> &) const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("__call__", (const opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("ChangeSeek", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> * (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("ChangeFind", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("__call__", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Integer &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Clear", [](MeshVS_DataMapOfHArray1OfSequenceOfInteger &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Clear", (void (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const Standard_Boolean)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Clear", (void (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("Size", (Standard_Integer (MeshVS_DataMapOfHArray1OfSequenceOfInteger::*)() const ) &MeshVS_DataMapOfHArray1OfSequenceOfInteger::Size, "Size");
	cls_MeshVS_DataMapOfHArray1OfSequenceOfInteger.def("__iter__", [](const MeshVS_DataMapOfHArray1OfSequenceOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfHArray1OfSequenceOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerAsciiString, std::unique_ptr<MeshVS_DataMapOfIntegerAsciiString, Deleter<MeshVS_DataMapOfIntegerAsciiString>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerAsciiString(mod, "MeshVS_DataMapOfIntegerAsciiString", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerAsciiString.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerAsciiString.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def(py::init([] (const MeshVS_DataMapOfIntegerAsciiString &other) {return new MeshVS_DataMapOfIntegerAsciiString(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("begin", (MeshVS_DataMapOfIntegerAsciiString::iterator (MeshVS_DataMapOfIntegerAsciiString::*)() const ) &MeshVS_DataMapOfIntegerAsciiString::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerAsciiString.def("end", (MeshVS_DataMapOfIntegerAsciiString::iterator (MeshVS_DataMapOfIntegerAsciiString::*)() const ) &MeshVS_DataMapOfIntegerAsciiString::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerAsciiString.def("cbegin", (MeshVS_DataMapOfIntegerAsciiString::const_iterator (MeshVS_DataMapOfIntegerAsciiString::*)() const ) &MeshVS_DataMapOfIntegerAsciiString::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerAsciiString.def("cend", (MeshVS_DataMapOfIntegerAsciiString::const_iterator (MeshVS_DataMapOfIntegerAsciiString::*)() const ) &MeshVS_DataMapOfIntegerAsciiString::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Exchange", (void (MeshVS_DataMapOfIntegerAsciiString::*)(MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_DataMapOfIntegerAsciiString::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Assign", (MeshVS_DataMapOfIntegerAsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_DataMapOfIntegerAsciiString::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("assign", (MeshVS_DataMapOfIntegerAsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const MeshVS_DataMapOfIntegerAsciiString &)) &MeshVS_DataMapOfIntegerAsciiString::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("ReSize", (void (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerAsciiString::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &, const TCollection_AsciiString &)) &MeshVS_DataMapOfIntegerAsciiString::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerAsciiString.def("Bound", (TCollection_AsciiString * (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &, const TCollection_AsciiString &)) &MeshVS_DataMapOfIntegerAsciiString::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerAsciiString::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerAsciiString::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerAsciiString.def("Seek", (const TCollection_AsciiString * (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerAsciiString::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerAsciiString.def("Find", (const TCollection_AsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerAsciiString::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerAsciiString.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &, TCollection_AsciiString &) const ) &MeshVS_DataMapOfIntegerAsciiString::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("__call__", (const TCollection_AsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerAsciiString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerAsciiString.def("ChangeSeek", (TCollection_AsciiString * (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerAsciiString::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("ChangeFind", (TCollection_AsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerAsciiString::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("__call__", (TCollection_AsciiString & (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerAsciiString::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Clear", [](MeshVS_DataMapOfIntegerAsciiString &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Clear", (void (MeshVS_DataMapOfIntegerAsciiString::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerAsciiString::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Clear", (void (MeshVS_DataMapOfIntegerAsciiString::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerAsciiString::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerAsciiString.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerAsciiString::*)() const ) &MeshVS_DataMapOfIntegerAsciiString::Size, "Size");
	cls_MeshVS_DataMapOfIntegerAsciiString.def("__iter__", [](const MeshVS_DataMapOfIntegerAsciiString &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerAsciiString.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerBoolean, std::unique_ptr<MeshVS_DataMapOfIntegerBoolean, Deleter<MeshVS_DataMapOfIntegerBoolean>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerBoolean(mod, "MeshVS_DataMapOfIntegerBoolean", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerBoolean.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerBoolean.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerBoolean.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerBoolean.def(py::init([] (const MeshVS_DataMapOfIntegerBoolean &other) {return new MeshVS_DataMapOfIntegerBoolean(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("begin", (MeshVS_DataMapOfIntegerBoolean::iterator (MeshVS_DataMapOfIntegerBoolean::*)() const ) &MeshVS_DataMapOfIntegerBoolean::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerBoolean.def("end", (MeshVS_DataMapOfIntegerBoolean::iterator (MeshVS_DataMapOfIntegerBoolean::*)() const ) &MeshVS_DataMapOfIntegerBoolean::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerBoolean.def("cbegin", (MeshVS_DataMapOfIntegerBoolean::const_iterator (MeshVS_DataMapOfIntegerBoolean::*)() const ) &MeshVS_DataMapOfIntegerBoolean::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerBoolean.def("cend", (MeshVS_DataMapOfIntegerBoolean::const_iterator (MeshVS_DataMapOfIntegerBoolean::*)() const ) &MeshVS_DataMapOfIntegerBoolean::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerBoolean.def("Exchange", (void (MeshVS_DataMapOfIntegerBoolean::*)(MeshVS_DataMapOfIntegerBoolean &)) &MeshVS_DataMapOfIntegerBoolean::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("Assign", (MeshVS_DataMapOfIntegerBoolean & (MeshVS_DataMapOfIntegerBoolean::*)(const MeshVS_DataMapOfIntegerBoolean &)) &MeshVS_DataMapOfIntegerBoolean::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("assign", (MeshVS_DataMapOfIntegerBoolean & (MeshVS_DataMapOfIntegerBoolean::*)(const MeshVS_DataMapOfIntegerBoolean &)) &MeshVS_DataMapOfIntegerBoolean::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("ReSize", (void (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerBoolean::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &, const Standard_Boolean &)) &MeshVS_DataMapOfIntegerBoolean::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerBoolean.def("Bound", (Standard_Boolean * (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &, const Standard_Boolean &)) &MeshVS_DataMapOfIntegerBoolean::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerBoolean::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerBoolean::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerBoolean.def("Seek", (const Standard_Boolean * (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerBoolean::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerBoolean.def("Find", (const Standard_Boolean & (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerBoolean::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerBoolean.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &, Standard_Boolean &) const ) &MeshVS_DataMapOfIntegerBoolean::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("__call__", (const Standard_Boolean & (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerBoolean::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerBoolean.def("ChangeSeek", (Standard_Boolean * (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerBoolean::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("ChangeFind", (Standard_Boolean & (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerBoolean::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("__call__", (Standard_Boolean & (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerBoolean::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("Clear", [](MeshVS_DataMapOfIntegerBoolean &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerBoolean.def("Clear", (void (MeshVS_DataMapOfIntegerBoolean::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerBoolean::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("Clear", (void (MeshVS_DataMapOfIntegerBoolean::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerBoolean::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerBoolean.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerBoolean::*)() const ) &MeshVS_DataMapOfIntegerBoolean::Size, "Size");
	cls_MeshVS_DataMapOfIntegerBoolean.def("__iter__", [](const MeshVS_DataMapOfIntegerBoolean &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerBoolean.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerColor, std::unique_ptr<MeshVS_DataMapOfIntegerColor, Deleter<MeshVS_DataMapOfIntegerColor>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerColor(mod, "MeshVS_DataMapOfIntegerColor", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerColor.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerColor.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerColor.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerColor.def(py::init([] (const MeshVS_DataMapOfIntegerColor &other) {return new MeshVS_DataMapOfIntegerColor(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerColor.def("begin", (MeshVS_DataMapOfIntegerColor::iterator (MeshVS_DataMapOfIntegerColor::*)() const ) &MeshVS_DataMapOfIntegerColor::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerColor.def("end", (MeshVS_DataMapOfIntegerColor::iterator (MeshVS_DataMapOfIntegerColor::*)() const ) &MeshVS_DataMapOfIntegerColor::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerColor.def("cbegin", (MeshVS_DataMapOfIntegerColor::const_iterator (MeshVS_DataMapOfIntegerColor::*)() const ) &MeshVS_DataMapOfIntegerColor::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerColor.def("cend", (MeshVS_DataMapOfIntegerColor::const_iterator (MeshVS_DataMapOfIntegerColor::*)() const ) &MeshVS_DataMapOfIntegerColor::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerColor.def("Exchange", (void (MeshVS_DataMapOfIntegerColor::*)(MeshVS_DataMapOfIntegerColor &)) &MeshVS_DataMapOfIntegerColor::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerColor.def("Assign", (MeshVS_DataMapOfIntegerColor & (MeshVS_DataMapOfIntegerColor::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_DataMapOfIntegerColor::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerColor.def("assign", (MeshVS_DataMapOfIntegerColor & (MeshVS_DataMapOfIntegerColor::*)(const MeshVS_DataMapOfIntegerColor &)) &MeshVS_DataMapOfIntegerColor::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerColor.def("ReSize", (void (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerColor::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerColor.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &, const Quantity_Color &)) &MeshVS_DataMapOfIntegerColor::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerColor.def("Bound", (Quantity_Color * (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &, const Quantity_Color &)) &MeshVS_DataMapOfIntegerColor::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerColor.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerColor::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerColor.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerColor::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerColor.def("Seek", (const Quantity_Color * (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerColor::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerColor.def("Find", (const Quantity_Color & (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerColor::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerColor.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &, Quantity_Color &) const ) &MeshVS_DataMapOfIntegerColor::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerColor.def("__call__", (const Quantity_Color & (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerColor::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerColor.def("ChangeSeek", (Quantity_Color * (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerColor::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerColor.def("ChangeFind", (Quantity_Color & (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerColor::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerColor.def("__call__", (Quantity_Color & (MeshVS_DataMapOfIntegerColor::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerColor::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerColor.def("Clear", [](MeshVS_DataMapOfIntegerColor &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerColor.def("Clear", (void (MeshVS_DataMapOfIntegerColor::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerColor::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerColor.def("Clear", (void (MeshVS_DataMapOfIntegerColor::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerColor::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerColor.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerColor::*)() const ) &MeshVS_DataMapOfIntegerColor::Size, "Size");
	cls_MeshVS_DataMapOfIntegerColor.def("__iter__", [](const MeshVS_DataMapOfIntegerColor &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerColor.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerMaterial, std::unique_ptr<MeshVS_DataMapOfIntegerMaterial, Deleter<MeshVS_DataMapOfIntegerMaterial>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerMaterial(mod, "MeshVS_DataMapOfIntegerMaterial", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerMaterial.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerMaterial.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerMaterial.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerMaterial.def(py::init([] (const MeshVS_DataMapOfIntegerMaterial &other) {return new MeshVS_DataMapOfIntegerMaterial(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("begin", (MeshVS_DataMapOfIntegerMaterial::iterator (MeshVS_DataMapOfIntegerMaterial::*)() const ) &MeshVS_DataMapOfIntegerMaterial::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerMaterial.def("end", (MeshVS_DataMapOfIntegerMaterial::iterator (MeshVS_DataMapOfIntegerMaterial::*)() const ) &MeshVS_DataMapOfIntegerMaterial::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerMaterial.def("cbegin", (MeshVS_DataMapOfIntegerMaterial::const_iterator (MeshVS_DataMapOfIntegerMaterial::*)() const ) &MeshVS_DataMapOfIntegerMaterial::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerMaterial.def("cend", (MeshVS_DataMapOfIntegerMaterial::const_iterator (MeshVS_DataMapOfIntegerMaterial::*)() const ) &MeshVS_DataMapOfIntegerMaterial::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerMaterial.def("Exchange", (void (MeshVS_DataMapOfIntegerMaterial::*)(MeshVS_DataMapOfIntegerMaterial &)) &MeshVS_DataMapOfIntegerMaterial::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("Assign", (MeshVS_DataMapOfIntegerMaterial & (MeshVS_DataMapOfIntegerMaterial::*)(const MeshVS_DataMapOfIntegerMaterial &)) &MeshVS_DataMapOfIntegerMaterial::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("assign", (MeshVS_DataMapOfIntegerMaterial & (MeshVS_DataMapOfIntegerMaterial::*)(const MeshVS_DataMapOfIntegerMaterial &)) &MeshVS_DataMapOfIntegerMaterial::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("ReSize", (void (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerMaterial::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &, const Graphic3d_MaterialAspect &)) &MeshVS_DataMapOfIntegerMaterial::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerMaterial.def("Bound", (Graphic3d_MaterialAspect * (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &, const Graphic3d_MaterialAspect &)) &MeshVS_DataMapOfIntegerMaterial::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMaterial::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMaterial::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMaterial.def("Seek", (const Graphic3d_MaterialAspect * (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMaterial::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMaterial.def("Find", (const Graphic3d_MaterialAspect & (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMaterial::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMaterial.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &, Graphic3d_MaterialAspect &) const ) &MeshVS_DataMapOfIntegerMaterial::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("__call__", (const Graphic3d_MaterialAspect & (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMaterial::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMaterial.def("ChangeSeek", (Graphic3d_MaterialAspect * (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMaterial::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("ChangeFind", (Graphic3d_MaterialAspect & (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMaterial::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("__call__", (Graphic3d_MaterialAspect & (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMaterial::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("Clear", [](MeshVS_DataMapOfIntegerMaterial &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerMaterial.def("Clear", (void (MeshVS_DataMapOfIntegerMaterial::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerMaterial::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("Clear", (void (MeshVS_DataMapOfIntegerMaterial::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerMaterial::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerMaterial.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerMaterial::*)() const ) &MeshVS_DataMapOfIntegerMaterial::Size, "Size");
	cls_MeshVS_DataMapOfIntegerMaterial.def("__iter__", [](const MeshVS_DataMapOfIntegerMaterial &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerMaterial.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerMeshEntityOwner, std::unique_ptr<MeshVS_DataMapOfIntegerMeshEntityOwner, Deleter<MeshVS_DataMapOfIntegerMeshEntityOwner>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerMeshEntityOwner(mod, "MeshVS_DataMapOfIntegerMeshEntityOwner", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def(py::init([] (const MeshVS_DataMapOfIntegerMeshEntityOwner &other) {return new MeshVS_DataMapOfIntegerMeshEntityOwner(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("begin", (MeshVS_DataMapOfIntegerMeshEntityOwner::iterator (MeshVS_DataMapOfIntegerMeshEntityOwner::*)() const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("end", (MeshVS_DataMapOfIntegerMeshEntityOwner::iterator (MeshVS_DataMapOfIntegerMeshEntityOwner::*)() const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("cbegin", (MeshVS_DataMapOfIntegerMeshEntityOwner::const_iterator (MeshVS_DataMapOfIntegerMeshEntityOwner::*)() const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("cend", (MeshVS_DataMapOfIntegerMeshEntityOwner::const_iterator (MeshVS_DataMapOfIntegerMeshEntityOwner::*)() const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Exchange", (void (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(MeshVS_DataMapOfIntegerMeshEntityOwner &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Assign", (MeshVS_DataMapOfIntegerMeshEntityOwner & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const MeshVS_DataMapOfIntegerMeshEntityOwner &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("assign", (MeshVS_DataMapOfIntegerMeshEntityOwner & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const MeshVS_DataMapOfIntegerMeshEntityOwner &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("ReSize", (void (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerMeshEntityOwner::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &, const opencascade::handle<MeshVS_MeshEntityOwner> &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Bound", (opencascade::handle<MeshVS_MeshEntityOwner> * (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &, const opencascade::handle<MeshVS_MeshEntityOwner> &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Seek", (const opencascade::handle<MeshVS_MeshEntityOwner> * (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Find", (const opencascade::handle<MeshVS_MeshEntityOwner> & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &, opencascade::handle<MeshVS_MeshEntityOwner> &) const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("__call__", (const opencascade::handle<MeshVS_MeshEntityOwner> & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("ChangeSeek", (opencascade::handle<MeshVS_MeshEntityOwner> * (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("ChangeFind", (opencascade::handle<MeshVS_MeshEntityOwner> & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("__call__", (opencascade::handle<MeshVS_MeshEntityOwner> & (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Clear", [](MeshVS_DataMapOfIntegerMeshEntityOwner &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Clear", (void (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Clear", (void (MeshVS_DataMapOfIntegerMeshEntityOwner::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerMeshEntityOwner::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerMeshEntityOwner::*)() const ) &MeshVS_DataMapOfIntegerMeshEntityOwner::Size, "Size");
	cls_MeshVS_DataMapOfIntegerMeshEntityOwner.def("__iter__", [](const MeshVS_DataMapOfIntegerMeshEntityOwner &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerMeshEntityOwner.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_TwoColors.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerTwoColors, std::unique_ptr<MeshVS_DataMapOfIntegerTwoColors, Deleter<MeshVS_DataMapOfIntegerTwoColors>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerTwoColors(mod, "MeshVS_DataMapOfIntegerTwoColors", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerTwoColors.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerTwoColors.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def(py::init([] (const MeshVS_DataMapOfIntegerTwoColors &other) {return new MeshVS_DataMapOfIntegerTwoColors(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("begin", (MeshVS_DataMapOfIntegerTwoColors::iterator (MeshVS_DataMapOfIntegerTwoColors::*)() const ) &MeshVS_DataMapOfIntegerTwoColors::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerTwoColors.def("end", (MeshVS_DataMapOfIntegerTwoColors::iterator (MeshVS_DataMapOfIntegerTwoColors::*)() const ) &MeshVS_DataMapOfIntegerTwoColors::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerTwoColors.def("cbegin", (MeshVS_DataMapOfIntegerTwoColors::const_iterator (MeshVS_DataMapOfIntegerTwoColors::*)() const ) &MeshVS_DataMapOfIntegerTwoColors::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerTwoColors.def("cend", (MeshVS_DataMapOfIntegerTwoColors::const_iterator (MeshVS_DataMapOfIntegerTwoColors::*)() const ) &MeshVS_DataMapOfIntegerTwoColors::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Exchange", (void (MeshVS_DataMapOfIntegerTwoColors::*)(MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_DataMapOfIntegerTwoColors::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Assign", (MeshVS_DataMapOfIntegerTwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_DataMapOfIntegerTwoColors::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("assign", (MeshVS_DataMapOfIntegerTwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const MeshVS_DataMapOfIntegerTwoColors &)) &MeshVS_DataMapOfIntegerTwoColors::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("ReSize", (void (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerTwoColors::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &, const MeshVS_TwoColors &)) &MeshVS_DataMapOfIntegerTwoColors::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerTwoColors.def("Bound", (MeshVS_TwoColors * (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &, const MeshVS_TwoColors &)) &MeshVS_DataMapOfIntegerTwoColors::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerTwoColors::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerTwoColors::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerTwoColors.def("Seek", (const MeshVS_TwoColors * (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerTwoColors::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerTwoColors.def("Find", (const MeshVS_TwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerTwoColors::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerTwoColors.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &, MeshVS_TwoColors &) const ) &MeshVS_DataMapOfIntegerTwoColors::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("__call__", (const MeshVS_TwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerTwoColors::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerTwoColors.def("ChangeSeek", (MeshVS_TwoColors * (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerTwoColors::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("ChangeFind", (MeshVS_TwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerTwoColors::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("__call__", (MeshVS_TwoColors & (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerTwoColors::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Clear", [](MeshVS_DataMapOfIntegerTwoColors &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Clear", (void (MeshVS_DataMapOfIntegerTwoColors::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerTwoColors::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Clear", (void (MeshVS_DataMapOfIntegerTwoColors::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerTwoColors::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerTwoColors.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerTwoColors::*)() const ) &MeshVS_DataMapOfIntegerTwoColors::Size, "Size");
	cls_MeshVS_DataMapOfIntegerTwoColors.def("__iter__", [](const MeshVS_DataMapOfIntegerTwoColors &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerTwoColors.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfIntegerVector, std::unique_ptr<MeshVS_DataMapOfIntegerVector, Deleter<MeshVS_DataMapOfIntegerVector>>, NCollection_BaseMap> cls_MeshVS_DataMapOfIntegerVector(mod, "MeshVS_DataMapOfIntegerVector", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfIntegerVector.def(py::init<>());
	cls_MeshVS_DataMapOfIntegerVector.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfIntegerVector.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerVector.def(py::init([] (const MeshVS_DataMapOfIntegerVector &other) {return new MeshVS_DataMapOfIntegerVector(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfIntegerVector.def("begin", (MeshVS_DataMapOfIntegerVector::iterator (MeshVS_DataMapOfIntegerVector::*)() const ) &MeshVS_DataMapOfIntegerVector::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerVector.def("end", (MeshVS_DataMapOfIntegerVector::iterator (MeshVS_DataMapOfIntegerVector::*)() const ) &MeshVS_DataMapOfIntegerVector::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerVector.def("cbegin", (MeshVS_DataMapOfIntegerVector::const_iterator (MeshVS_DataMapOfIntegerVector::*)() const ) &MeshVS_DataMapOfIntegerVector::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfIntegerVector.def("cend", (MeshVS_DataMapOfIntegerVector::const_iterator (MeshVS_DataMapOfIntegerVector::*)() const ) &MeshVS_DataMapOfIntegerVector::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfIntegerVector.def("Exchange", (void (MeshVS_DataMapOfIntegerVector::*)(MeshVS_DataMapOfIntegerVector &)) &MeshVS_DataMapOfIntegerVector::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerVector.def("Assign", (MeshVS_DataMapOfIntegerVector & (MeshVS_DataMapOfIntegerVector::*)(const MeshVS_DataMapOfIntegerVector &)) &MeshVS_DataMapOfIntegerVector::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerVector.def("assign", (MeshVS_DataMapOfIntegerVector & (MeshVS_DataMapOfIntegerVector::*)(const MeshVS_DataMapOfIntegerVector &)) &MeshVS_DataMapOfIntegerVector::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfIntegerVector.def("ReSize", (void (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer)) &MeshVS_DataMapOfIntegerVector::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfIntegerVector.def("Bind", (Standard_Boolean (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &, const gp_Vec &)) &MeshVS_DataMapOfIntegerVector::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfIntegerVector.def("Bound", (gp_Vec * (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &, const gp_Vec &)) &MeshVS_DataMapOfIntegerVector::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfIntegerVector.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerVector::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerVector.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerVector::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerVector.def("Seek", (const gp_Vec * (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerVector::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerVector.def("Find", (const gp_Vec & (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerVector::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerVector.def("Find", (Standard_Boolean (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &, gp_Vec &) const ) &MeshVS_DataMapOfIntegerVector::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfIntegerVector.def("__call__", (const gp_Vec & (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &) const ) &MeshVS_DataMapOfIntegerVector::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfIntegerVector.def("ChangeSeek", (gp_Vec * (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerVector::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerVector.def("ChangeFind", (gp_Vec & (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerVector::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerVector.def("__call__", (gp_Vec & (MeshVS_DataMapOfIntegerVector::*)(const Standard_Integer &)) &MeshVS_DataMapOfIntegerVector::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfIntegerVector.def("Clear", [](MeshVS_DataMapOfIntegerVector &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfIntegerVector.def("Clear", (void (MeshVS_DataMapOfIntegerVector::*)(const Standard_Boolean)) &MeshVS_DataMapOfIntegerVector::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfIntegerVector.def("Clear", (void (MeshVS_DataMapOfIntegerVector::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfIntegerVector::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfIntegerVector.def("Size", (Standard_Integer (MeshVS_DataMapOfIntegerVector::*)() const ) &MeshVS_DataMapOfIntegerVector::Size, "Size");
	cls_MeshVS_DataMapOfIntegerVector.def("__iter__", [](const MeshVS_DataMapOfIntegerVector &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfIntegerVector.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<MeshVS_TwoColorsHasher, std::unique_ptr<MeshVS_TwoColorsHasher, Deleter<MeshVS_TwoColorsHasher>>> cls_MeshVS_TwoColorsHasher(mod, "MeshVS_TwoColorsHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_MeshVS_TwoColorsHasher.def(py::init<>());
	cls_MeshVS_TwoColorsHasher.def_static("HashCode_", (Standard_Integer (*)(const MeshVS_TwoColors &, const Standard_Integer)) &MeshVS_TwoColorsHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_MeshVS_TwoColorsHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MeshVS_TwoColors &, const MeshVS_TwoColors &)) &MeshVS_TwoColorsHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<MeshVS_DataMapOfTwoColorsMapOfInteger, std::unique_ptr<MeshVS_DataMapOfTwoColorsMapOfInteger, Deleter<MeshVS_DataMapOfTwoColorsMapOfInteger>>, NCollection_BaseMap> cls_MeshVS_DataMapOfTwoColorsMapOfInteger(mod, "MeshVS_DataMapOfTwoColorsMapOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def(py::init<>());
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def(py::init([] (const MeshVS_DataMapOfTwoColorsMapOfInteger &other) {return new MeshVS_DataMapOfTwoColorsMapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("begin", (MeshVS_DataMapOfTwoColorsMapOfInteger::iterator (MeshVS_DataMapOfTwoColorsMapOfInteger::*)() const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("end", (MeshVS_DataMapOfTwoColorsMapOfInteger::iterator (MeshVS_DataMapOfTwoColorsMapOfInteger::*)() const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("cbegin", (MeshVS_DataMapOfTwoColorsMapOfInteger::const_iterator (MeshVS_DataMapOfTwoColorsMapOfInteger::*)() const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("cend", (MeshVS_DataMapOfTwoColorsMapOfInteger::const_iterator (MeshVS_DataMapOfTwoColorsMapOfInteger::*)() const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Exchange", (void (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(MeshVS_DataMapOfTwoColorsMapOfInteger &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Assign", (MeshVS_DataMapOfTwoColorsMapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_DataMapOfTwoColorsMapOfInteger &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("assign", (MeshVS_DataMapOfTwoColorsMapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_DataMapOfTwoColorsMapOfInteger &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("ReSize", (void (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const Standard_Integer)) &MeshVS_DataMapOfTwoColorsMapOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Bind", (Standard_Boolean (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &, const TColStd_MapOfInteger &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Bound", (TColStd_MapOfInteger * (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &, const TColStd_MapOfInteger &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("IsBound", (Standard_Boolean (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &) const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("UnBind", (Standard_Boolean (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Seek", (const TColStd_MapOfInteger * (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &) const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Find", (const TColStd_MapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &) const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Find", (Standard_Boolean (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &, TColStd_MapOfInteger &) const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("__call__", (const TColStd_MapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &) const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("ChangeSeek", (TColStd_MapOfInteger * (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("ChangeFind", (TColStd_MapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("__call__", (TColStd_MapOfInteger & (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const MeshVS_TwoColors &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Clear", [](MeshVS_DataMapOfTwoColorsMapOfInteger &self) -> void { return self.Clear(); });
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Clear", (void (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const Standard_Boolean)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Clear", (void (MeshVS_DataMapOfTwoColorsMapOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_DataMapOfTwoColorsMapOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("Size", (Standard_Integer (MeshVS_DataMapOfTwoColorsMapOfInteger::*)() const ) &MeshVS_DataMapOfTwoColorsMapOfInteger::Size, "Size");
	cls_MeshVS_DataMapOfTwoColorsMapOfInteger.def("__iter__", [](const MeshVS_DataMapOfTwoColorsMapOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_DataMapOfTwoColorsMapOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DefaultHasher.hxx
	py::class_<MeshVS_TwoNodesHasher, std::unique_ptr<MeshVS_TwoNodesHasher, Deleter<MeshVS_TwoNodesHasher>>> cls_MeshVS_TwoNodesHasher(mod, "MeshVS_TwoNodesHasher", "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.");
	cls_MeshVS_TwoNodesHasher.def(py::init<>());
	cls_MeshVS_TwoNodesHasher.def_static("HashCode_", (Standard_Integer (*)(const MeshVS_TwoNodes &, const Standard_Integer)) &MeshVS_TwoNodesHasher::HashCode, "None", py::arg("theKey"), py::arg("Upper"));
	cls_MeshVS_TwoNodesHasher.def_static("IsEqual_", (Standard_Boolean (*)(const MeshVS_TwoNodes &, const MeshVS_TwoNodes &)) &MeshVS_TwoNodesHasher::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Map.hxx
	py::class_<MeshVS_MapOfTwoNodes, std::unique_ptr<MeshVS_MapOfTwoNodes, Deleter<MeshVS_MapOfTwoNodes>>, NCollection_BaseMap> cls_MeshVS_MapOfTwoNodes(mod, "MeshVS_MapOfTwoNodes", "Purpose: Single hashed Map. This Map is used to store and retrieve keys in linear time.");
	cls_MeshVS_MapOfTwoNodes.def(py::init<>());
	cls_MeshVS_MapOfTwoNodes.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_MeshVS_MapOfTwoNodes.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_MeshVS_MapOfTwoNodes.def(py::init([] (const MeshVS_MapOfTwoNodes &other) {return new MeshVS_MapOfTwoNodes(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_MapOfTwoNodes.def("cbegin", (MeshVS_MapOfTwoNodes::const_iterator (MeshVS_MapOfTwoNodes::*)() const ) &MeshVS_MapOfTwoNodes::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_MeshVS_MapOfTwoNodes.def("cend", (MeshVS_MapOfTwoNodes::const_iterator (MeshVS_MapOfTwoNodes::*)() const ) &MeshVS_MapOfTwoNodes::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_MeshVS_MapOfTwoNodes.def("Exchange", (void (MeshVS_MapOfTwoNodes::*)(MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("Assign", (MeshVS_MapOfTwoNodes & (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Assign, "Assign. This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("assign", (MeshVS_MapOfTwoNodes & (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::operator=, py::is_operator(), "Assign operator", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("ReSize", (void (MeshVS_MapOfTwoNodes::*)(const Standard_Integer)) &MeshVS_MapOfTwoNodes::ReSize, "ReSize", py::arg("N"));
	cls_MeshVS_MapOfTwoNodes.def("Add", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_TwoNodes &)) &MeshVS_MapOfTwoNodes::Add, "Add", py::arg("K"));
	cls_MeshVS_MapOfTwoNodes.def("Added", (const MeshVS_TwoNodes & (MeshVS_MapOfTwoNodes::*)(const MeshVS_TwoNodes &)) &MeshVS_MapOfTwoNodes::Added, "Added: add a new key if not yet in the map, and return reference to either newly added or previously existing object", py::arg("K"));
	cls_MeshVS_MapOfTwoNodes.def("Contains", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_TwoNodes &) const ) &MeshVS_MapOfTwoNodes::Contains, "Contains", py::arg("K"));
	cls_MeshVS_MapOfTwoNodes.def("Remove", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_TwoNodes &)) &MeshVS_MapOfTwoNodes::Remove, "Remove", py::arg("K"));
	cls_MeshVS_MapOfTwoNodes.def("Clear", [](MeshVS_MapOfTwoNodes &self) -> void { return self.Clear(); });
	cls_MeshVS_MapOfTwoNodes.def("Clear", (void (MeshVS_MapOfTwoNodes::*)(const Standard_Boolean)) &MeshVS_MapOfTwoNodes::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_MeshVS_MapOfTwoNodes.def("Clear", (void (MeshVS_MapOfTwoNodes::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_MapOfTwoNodes::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_MeshVS_MapOfTwoNodes.def("Size", (Standard_Integer (MeshVS_MapOfTwoNodes::*)() const ) &MeshVS_MapOfTwoNodes::Size, "Size");
	cls_MeshVS_MapOfTwoNodes.def("IsEqual", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &) const ) &MeshVS_MapOfTwoNodes::IsEqual, "Returns true if two maps contains exactly the same keys", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("Contains", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &) const ) &MeshVS_MapOfTwoNodes::Contains, "Returns true if this map contains ALL keys of another map.", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("Union", (void (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &, const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Union, "Sets this Map to be the result of union (aka addition, fuse, merge, boolean OR) operation between two given Maps The new Map contains the values that are contained either in the first map or in the second map or in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be passed as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_MeshVS_MapOfTwoNodes.def("Unite", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Unite, "Apply to this Map the boolean operation union (aka addition, fuse, merge, boolean OR) with another (given) Map. The result contains the values that were previously contained in this map or contained in the given (operand) map. This algorithm is similar to method Union(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("HasIntersection", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &) const ) &MeshVS_MapOfTwoNodes::HasIntersection, "Returns true if this and theMap have common elements.", py::arg("theMap"));
	cls_MeshVS_MapOfTwoNodes.def("Intersection", (void (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &, const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Intersection, "Sets this Map to be the result of intersection (aka multiplication, common, boolean AND) operation between two given Maps. The new Map contains only the values that are contained in both map operands. All previous content of this Map is cleared. This same map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_MeshVS_MapOfTwoNodes.def("Intersect", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Intersect, "Apply to this Map the intersection operation (aka multiplication, common, boolean AND) with another (given) Map. The result contains only the values that are contained in both this and the given maps. This algorithm is similar to method Intersection(). Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("Subtraction", (void (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &, const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Subtraction, "Sets this Map to be the result of subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation between two given Maps. The new Map contains only the values that are contained in the first map operands and not contained in the second one. All previous content of this Map is cleared.", py::arg("theLeft"), py::arg("theRight"));
	cls_MeshVS_MapOfTwoNodes.def("Subtract", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Subtract, "Apply to this Map the subtraction (aka set-theoretic difference, relative complement, exclude, cut, boolean NOT) operation with another (given) Map. The result contains only the values that were previously contained in this map and not contained in this map. This algorithm is similar to method Subtract() with two operands. Returns True if contents of this map is changed.", py::arg("theOther"));
	cls_MeshVS_MapOfTwoNodes.def("Difference", (void (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &, const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Difference, "Sets this Map to be the result of symmetric difference (aka exclusive disjunction, boolean XOR) operation between two given Maps. The new Map contains the values that are contained only in the first or the second operand maps but not in both. All previous content of this Map is cleared. This map (result of the boolean operation) can also be used as one of operands.", py::arg("theLeft"), py::arg("theRight"));
	cls_MeshVS_MapOfTwoNodes.def("Differ", (Standard_Boolean (MeshVS_MapOfTwoNodes::*)(const MeshVS_MapOfTwoNodes &)) &MeshVS_MapOfTwoNodes::Differ, "Apply to this Map the symmetric difference (aka exclusive disjunction, boolean XOR) operation with another (given) Map. The result contains the values that are contained only in this or the operand map, but not in both. This algorithm is similar to method Difference(). Returns True if contents of this map is changed.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_MapOfTwoNodes.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\MeshVS_SelectionModeFlags.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<MeshVS_PolyhedronVerts, std::unique_ptr<MeshVS_PolyhedronVerts, Deleter<MeshVS_PolyhedronVerts>>, NCollection_BaseList> cls_MeshVS_PolyhedronVerts(mod, "MeshVS_PolyhedronVerts", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_MeshVS_PolyhedronVerts.def(py::init<>());
	cls_MeshVS_PolyhedronVerts.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_MeshVS_PolyhedronVerts.def(py::init([] (const MeshVS_PolyhedronVerts &other) {return new MeshVS_PolyhedronVerts(other);}), "Copy constructor", py::arg("other"));
	cls_MeshVS_PolyhedronVerts.def("begin", (MeshVS_PolyhedronVerts::iterator (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::begin, "Returns an iterator pointing to the first element in the list.");
	cls_MeshVS_PolyhedronVerts.def("end", (MeshVS_PolyhedronVerts::iterator (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_MeshVS_PolyhedronVerts.def("cbegin", (MeshVS_PolyhedronVerts::const_iterator (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_MeshVS_PolyhedronVerts.def("cend", (MeshVS_PolyhedronVerts::const_iterator (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_MeshVS_PolyhedronVerts.def("Size", (Standard_Integer (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::Size, "Size - Number of items");
	cls_MeshVS_PolyhedronVerts.def("Assign", (MeshVS_PolyhedronVerts & (MeshVS_PolyhedronVerts::*)(const MeshVS_PolyhedronVerts &)) &MeshVS_PolyhedronVerts::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_MeshVS_PolyhedronVerts.def("assign", (MeshVS_PolyhedronVerts & (MeshVS_PolyhedronVerts::*)(const MeshVS_PolyhedronVerts &)) &MeshVS_PolyhedronVerts::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_MeshVS_PolyhedronVerts.def("Clear", [](MeshVS_PolyhedronVerts &self) -> void { return self.Clear(); });
	cls_MeshVS_PolyhedronVerts.def("Clear", (void (MeshVS_PolyhedronVerts::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &MeshVS_PolyhedronVerts::Clear, "Clear this list", py::arg("theAllocator"));
	cls_MeshVS_PolyhedronVerts.def("First", (const opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::First, "First item");
	cls_MeshVS_PolyhedronVerts.def("First", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)()) &MeshVS_PolyhedronVerts::First, "First item (non-const)");
	cls_MeshVS_PolyhedronVerts.def("Last", (const opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)() const ) &MeshVS_PolyhedronVerts::Last, "Last item");
	cls_MeshVS_PolyhedronVerts.def("Last", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)()) &MeshVS_PolyhedronVerts::Last, "Last item (non-const)");
	cls_MeshVS_PolyhedronVerts.def("Append", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)(const opencascade::handle<TColgp_HArray1OfPnt> &)) &MeshVS_PolyhedronVerts::Append, "Append one item at the end", py::arg("theItem"));
	cls_MeshVS_PolyhedronVerts.def("Append", (void (MeshVS_PolyhedronVerts::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("Append", (void (MeshVS_PolyhedronVerts::*)(MeshVS_PolyhedronVerts &)) &MeshVS_PolyhedronVerts::Append, "Append another list at the end", py::arg("theOther"));
	cls_MeshVS_PolyhedronVerts.def("Prepend", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)(const opencascade::handle<TColgp_HArray1OfPnt> &)) &MeshVS_PolyhedronVerts::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_MeshVS_PolyhedronVerts.def("Prepend", (void (MeshVS_PolyhedronVerts::*)(MeshVS_PolyhedronVerts &)) &MeshVS_PolyhedronVerts::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_MeshVS_PolyhedronVerts.def("RemoveFirst", (void (MeshVS_PolyhedronVerts::*)()) &MeshVS_PolyhedronVerts::RemoveFirst, "RemoveFirst item");
	cls_MeshVS_PolyhedronVerts.def("Remove", (void (MeshVS_PolyhedronVerts::*)(MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("InsertBefore", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("InsertBefore", (void (MeshVS_PolyhedronVerts::*)(MeshVS_PolyhedronVerts &, MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("InsertAfter", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVerts::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("InsertAfter", (void (MeshVS_PolyhedronVerts::*)(MeshVS_PolyhedronVerts &, MeshVS_PolyhedronVerts::Iterator &)) &MeshVS_PolyhedronVerts::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_MeshVS_PolyhedronVerts.def("Reverse", (void (MeshVS_PolyhedronVerts::*)()) &MeshVS_PolyhedronVerts::Reverse, "Reverse the list");
	cls_MeshVS_PolyhedronVerts.def("__iter__", [](const MeshVS_PolyhedronVerts &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<MeshVS_PolyhedronVertsIter, std::unique_ptr<MeshVS_PolyhedronVertsIter, Deleter<MeshVS_PolyhedronVertsIter>>> cls_MeshVS_PolyhedronVertsIter(mod, "MeshVS_PolyhedronVertsIter", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_MeshVS_PolyhedronVertsIter.def(py::init<>());
	cls_MeshVS_PolyhedronVertsIter.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_MeshVS_PolyhedronVertsIter.def("More", (Standard_Boolean (MeshVS_PolyhedronVertsIter::*)() const ) &MeshVS_PolyhedronVertsIter::More, "Check end");
	cls_MeshVS_PolyhedronVertsIter.def("Next", (void (MeshVS_PolyhedronVertsIter::*)()) &MeshVS_PolyhedronVertsIter::Next, "Make step");
	cls_MeshVS_PolyhedronVertsIter.def("Value", (const opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVertsIter::*)() const ) &MeshVS_PolyhedronVertsIter::Value, "Constant Value access");
	cls_MeshVS_PolyhedronVertsIter.def("Value", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVertsIter::*)()) &MeshVS_PolyhedronVertsIter::Value, "Non-const Value access");
	cls_MeshVS_PolyhedronVertsIter.def("ChangeValue", (opencascade::handle<TColgp_HArray1OfPnt> & (MeshVS_PolyhedronVertsIter::*)() const ) &MeshVS_PolyhedronVertsIter::ChangeValue, "Non-const Value access");

	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_EncodedLink")) {
		mod.attr("MeshVS_NodePair") = other_mod.attr("BVH_EncodedLink");
	}


}
