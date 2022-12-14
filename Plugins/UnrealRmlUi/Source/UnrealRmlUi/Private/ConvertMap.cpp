﻿#include "UnrealRmlUi.h"

TMap<FKey, Rml::Input::KeyIdentifier> KeyConvertMap = {
	{ EKeys::Zero, Rml::Input::KeyIdentifier::KI_0 },
	{ EKeys::One, Rml::Input::KeyIdentifier::KI_1 },
	{ EKeys::Two, Rml::Input::KeyIdentifier::KI_2 },
	{ EKeys::Three, Rml::Input::KeyIdentifier::KI_3 },
	{ EKeys::Four, Rml::Input::KeyIdentifier::KI_4 },
	{ EKeys::Five, Rml::Input::KeyIdentifier::KI_5 },
	{ EKeys::Six, Rml::Input::KeyIdentifier::KI_6 },
	{ EKeys::Seven, Rml::Input::KeyIdentifier::KI_7 },
	{ EKeys::Eight, Rml::Input::KeyIdentifier::KI_8 },
	{ EKeys::Nine, Rml::Input::KeyIdentifier::KI_9 },
	{ EKeys::A, Rml::Input::KeyIdentifier::KI_A },
	{ EKeys::B, Rml::Input::KeyIdentifier::KI_B },
	{ EKeys::C, Rml::Input::KeyIdentifier::KI_C },
	{ EKeys::D, Rml::Input::KeyIdentifier::KI_D },
	{ EKeys::E, Rml::Input::KeyIdentifier::KI_E },
	{ EKeys::F, Rml::Input::KeyIdentifier::KI_F },
	{ EKeys::G, Rml::Input::KeyIdentifier::KI_G },
	{ EKeys::H, Rml::Input::KeyIdentifier::KI_H },
	{ EKeys::I, Rml::Input::KeyIdentifier::KI_I },
	{ EKeys::J, Rml::Input::KeyIdentifier::KI_J },
	{ EKeys::K, Rml::Input::KeyIdentifier::KI_K },
	{ EKeys::L, Rml::Input::KeyIdentifier::KI_L },
	{ EKeys::M, Rml::Input::KeyIdentifier::KI_M },
	{ EKeys::N, Rml::Input::KeyIdentifier::KI_N },
	{ EKeys::O, Rml::Input::KeyIdentifier::KI_O },
	{ EKeys::P, Rml::Input::KeyIdentifier::KI_P },
	{ EKeys::Q, Rml::Input::KeyIdentifier::KI_Q },
	{ EKeys::R, Rml::Input::KeyIdentifier::KI_R },
	{ EKeys::S, Rml::Input::KeyIdentifier::KI_S },
	{ EKeys::T, Rml::Input::KeyIdentifier::KI_T },
	{ EKeys::U, Rml::Input::KeyIdentifier::KI_U },
	{ EKeys::V, Rml::Input::KeyIdentifier::KI_V },
	{ EKeys::W, Rml::Input::KeyIdentifier::KI_W },
	{ EKeys::X, Rml::Input::KeyIdentifier::KI_X },
	{ EKeys::Y, Rml::Input::KeyIdentifier::KI_Y },
	{ EKeys::Z, Rml::Input::KeyIdentifier::KI_Z },
	{ EKeys::NumPadZero, Rml::Input::KeyIdentifier::KI_NUMPAD0 },
	{ EKeys::NumPadOne, Rml::Input::KeyIdentifier::KI_NUMPAD1 },
	{ EKeys::NumPadTwo, Rml::Input::KeyIdentifier::KI_NUMPAD2 },
	{ EKeys::NumPadThree, Rml::Input::KeyIdentifier::KI_NUMPAD3 },
	{ EKeys::NumPadFour, Rml::Input::KeyIdentifier::KI_NUMPAD4 },
	{ EKeys::NumPadFive, Rml::Input::KeyIdentifier::KI_NUMPAD5 },
	{ EKeys::NumPadSix, Rml::Input::KeyIdentifier::KI_NUMPAD6 },
	{ EKeys::NumPadSeven, Rml::Input::KeyIdentifier::KI_NUMPAD7 },
	{ EKeys::NumPadEight, Rml::Input::KeyIdentifier::KI_NUMPAD8 },
	{ EKeys::NumPadNine, Rml::Input::KeyIdentifier::KI_NUMPAD9 },
	{ EKeys::F1, Rml::Input::KeyIdentifier::KI_F1 },
	{ EKeys::F2, Rml::Input::KeyIdentifier::KI_F2 },
	{ EKeys::F3, Rml::Input::KeyIdentifier::KI_F3 },
	{ EKeys::F4, Rml::Input::KeyIdentifier::KI_F4 },
	{ EKeys::F5, Rml::Input::KeyIdentifier::KI_F5 },
	{ EKeys::F6, Rml::Input::KeyIdentifier::KI_F6 },
	{ EKeys::F7, Rml::Input::KeyIdentifier::KI_F7 },
	{ EKeys::F8, Rml::Input::KeyIdentifier::KI_F8 },
	{ EKeys::F9, Rml::Input::KeyIdentifier::KI_F9 },
	{ EKeys::F10, Rml::Input::KeyIdentifier::KI_F10 },
	{ EKeys::F11, Rml::Input::KeyIdentifier::KI_F11 },
	{ EKeys::F12, Rml::Input::KeyIdentifier::KI_F12 },
	{ EKeys::Enter, Rml::Input::KeyIdentifier::KI_RETURN },
	{ EKeys::SpaceBar, Rml::Input::KeyIdentifier::KI_SPACE },
	{ EKeys::Escape, Rml::Input::KeyIdentifier::KI_ESCAPE },
	{ EKeys::Multiply, Rml::Input::KeyIdentifier::KI_MULTIPLY },
	{ EKeys::Add, Rml::Input::KeyIdentifier::KI_ADD },
	{ EKeys::Subtract, Rml::Input::KeyIdentifier::KI_SUBTRACT },
	{ EKeys::Decimal, Rml::Input::KeyIdentifier::KI_DECIMAL },
	{ EKeys::Divide, Rml::Input::KeyIdentifier::KI_DIVIDE },
	{ EKeys::PageUp, Rml::Input::KeyIdentifier::KI_PRIOR },
	{ EKeys::PageDown, Rml::Input::KeyIdentifier::KI_NEXT },
	{ EKeys::End, Rml::Input::KeyIdentifier::KI_END },
	{ EKeys::Home, Rml::Input::KeyIdentifier::KI_HOME },
	{ EKeys::Left, Rml::Input::KeyIdentifier::KI_LEFT },
	{ EKeys::Right, Rml::Input::KeyIdentifier::KI_RIGHT },
    { EKeys::Down, Rml::Input::KeyIdentifier::KI_DOWN },
    { EKeys::Up, Rml::Input::KeyIdentifier::KI_UP },
    { EKeys::Insert, Rml::Input::KeyIdentifier::KI_INSERT },
    { EKeys::Delete, Rml::Input::KeyIdentifier::KI_DELETE },
	{ EKeys::BackSpace, Rml::Input::KeyIdentifier::KI_BACK },
	{ EKeys::LeftShift, Rml::Input::KeyIdentifier::KI_LSHIFT },
	{ EKeys::RightShift, Rml::Input::KeyIdentifier::KI_RSHIFT },
	{ EKeys::LeftControl, Rml::Input::KeyIdentifier::KI_LCONTROL },
	{ EKeys::RightControl, Rml::Input::KeyIdentifier::KI_RCONTROL },
	{ EKeys::NumLock, Rml::Input::KeyIdentifier::KI_NUMLOCK },
	{ EKeys::ScrollLock, Rml::Input::KeyIdentifier::KI_SCROLL },
};

TMap<FKey, int> MouseConvertMap = {
	{ EKeys::LeftMouseButton, 0 },
	{ EKeys::RightMouseButton, 1 },
	{ EKeys::MiddleMouseButton, 2 },
	{ EKeys::ThumbMouseButton, 3 },
	{ EKeys::ThumbMouseButton2, 4 },
};
