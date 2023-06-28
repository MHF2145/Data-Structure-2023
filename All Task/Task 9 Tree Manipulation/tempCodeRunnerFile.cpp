        case 4:
            printf("Exiting program.\n");
            deleteTree(root);
            break;

        default:
            printf("Invalid choice.\n");
        }

        do
        {
            printf("so.... Continue? (y/n): ");
            scanf(" %c", &cont);
        } while (cont != 'y' && cont != 'n');

    } while (cont == 'y');

    return 0;
}
